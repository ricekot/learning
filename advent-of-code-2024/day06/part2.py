from copy import deepcopy
from functools import cmp_to_key
from pathlib import Path
import sys

if len(sys.argv) != 2:
    print("Usage: python part2.py input.txt")
    sys.exit(1)

input_file = Path(sys.argv[1])
guard_map: list[str] = []

with open(input_file, "r") as f:
    for line in f.readlines():
        guard_map.append(list(line.strip()))

map_height = len(guard_map)
map_width = len(guard_map[0])

for y in range(map_height):
    for x in range(map_width):
        if guard_map[y][x] == "^":
            starting_x = x
            starting_y = y
            break

directions = [(0, -1), (1, 0), (0, 1), (-1, 0)]

x, y = starting_x, starting_y

guard_map_copy = deepcopy(guard_map)
turns = 0
step_x, step_y = directions[0]
coordinates_covered = []
while x < map_width and y < map_height:
    if guard_map_copy[y][x] == "#":
        # take a step back and turn
        x -= step_x
        y -= step_y
        turns += 1
        step_x, step_y = directions[turns % 4]
        continue
    elif guard_map_copy[y][x] != "X":
        coordinates_covered.append((x, y))
        guard_map_copy[y][x] = "X"
    x += step_x
    y += step_y


positions = 0
for coordinates in coordinates_covered:
    guard_map_copy = deepcopy(guard_map)
    obstacle_x, obstacle_y = coordinates
    guard_map_copy[obstacle_y][obstacle_x] = "#"

    x, y = starting_x, starting_y
    turns = 0
    step_x, step_y = directions[0]
    while 0 <= x < map_width and 0 <= y < map_height:
        if guard_map_copy[y][x] == "#":
            # take a step back and turn
            x -= step_x
            y -= step_y
            turns += 1
            step_x, step_y = directions[turns % 4]
            continue
        elif guard_map_copy[y][x] in (".", "^"):
            guard_map_copy[y][x] = str(turns % 4)
        elif guard_map_copy[y][x] == str(turns % 4):
            positions += 1
            # for row in guard_map_copy:
            #     print("".join(row))
            # print()
            break

        x += step_x
        y += step_y

print(positions)

from functools import cmp_to_key
from pathlib import Path
import sys

if len(sys.argv) != 2:
    print("Usage: python part1.py input.txt")
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

turns = 0
step_x, step_y = directions[0]
positions = 0
while x < map_width and y < map_height:
    if guard_map[y][x] == "#":
        # take a step back and turn
        x -= step_x
        y -= step_y
        turns += 1
        step_x, step_y = directions[turns % 4]
        # for row in guard_map:
        #     print("".join(row))
        # print()
        continue
    elif guard_map[y][x] != "X":
        positions += 1
        guard_map[y][x] = "X"
    x += step_x
    y += step_y

print(positions)

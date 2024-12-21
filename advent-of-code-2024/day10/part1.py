import sys
from pathlib import Path

if len(sys.argv) != 2:
    print("Usage: python part1.py input.txt")
    sys.exit(1)

input_file = Path(sys.argv[1])
topographic_map = []
with open(input_file, "r") as f:
    for line in f.readlines():
        topographic_map.append(list(map(lambda x: int(x), line.strip())))

gridheight = len(topographic_map)
gridwidth = len(topographic_map[0])


def inside_grid(x: int, y: int) -> bool:
    return 0 <= x < gridwidth and 0 <= y < gridheight


result = 0


def score_trailhead(x: int, y: int):
    if not inside_grid(x, y):
        return
    height = topographic_map[y][x]
    if height == 9:
        global result
        result += 1
        topographic_map[y][x] = -5
        return

    neighbours = list(
        filter(
            lambda xy: topographic_map[xy[1]][xy[0]] == height + 1,
            filter(
                lambda xy: inside_grid(*xy),
                map(
                    lambda d: (x + d[0], y + d[1]),
                    [(0, -1), (0, 1), (-1, 0), (1, 0)],
                ),
            ),
        )
    )

    for x, y in neighbours:
        score_trailhead(x, y)


def reset_map():
    for y in range(gridheight):
        for x in range(gridwidth):
            if topographic_map[y][x] == -5:
                topographic_map[y][x] = 9


for y in range(gridheight):
    for x in range(gridwidth):
        if topographic_map[y][x] == 0:
            score_trailhead(x, y)
            reset_map()

print(result)

import itertools
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


def score_trailhead(x: int, y: int):
    if topographic_map[y][x] == 9:
        yield 1
        return

    yield from itertools.chain.from_iterable(
        map(
            lambda xy: score_trailhead(*xy),
            filter(
                lambda xy: topographic_map[xy[1]][xy[0]] == topographic_map[y][x] + 1,
                filter(
                    lambda xy: inside_grid(*xy),
                    map(
                        lambda d: (x + d[0], y + d[1]),
                        [(0, -1), (0, 1), (-1, 0), (1, 0)],
                    ),
                ),
            ),
        )
    )


print(
    sum(
        sum(score_trailhead(x, y))
        for y in range(gridheight)
        for x in range(gridwidth)
        if topographic_map[y][x] == 0
    )
)

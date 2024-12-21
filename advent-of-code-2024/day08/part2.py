import sys
from collections import defaultdict
from itertools import combinations
from pathlib import Path
from typing import Generator


def get_antinodes(
    antenna1: tuple[int, int], antenna2: tuple[int, int], gridwidth: int
) -> Generator[tuple[int, int], None, None]:
    (x1, y1) = antenna1
    (x2, y2) = antenna2

    for x in range(gridwidth):
        y = (y2 - y1) * (x - x1) / (x2 - x1) + y1
        if y == int(y):
            yield (x, int(y))


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python part2.py input.txt")
        sys.exit(1)

    input_file = Path(sys.argv[1])

    antennas = defaultdict(list)
    grid = []
    with open(input_file, "r") as f:
        for line in f.readlines():
            grid.append(list(line.strip()))

    gridheight = len(grid)
    gridwidth = len(grid[0])

    for y, line in enumerate(grid):
        for x, char in enumerate(line):
            if char != ".":
                antennas[char].append((x, y))

    # for line in grid:
    #     print("".join(line))
    # print()

    antinode_coordinates = set()
    for frequency, coordinates in antennas.items():
        for antenna1, antenna2 in combinations(coordinates, 2):
            for x, y in get_antinodes(antenna1, antenna2, gridwidth):
                if 0 <= x < gridwidth and 0 <= y < gridheight:
                    grid[y][x] = "#"
                    antinode_coordinates.add((x, y))

    # for line in grid:
    #     print("".join(line))
    # print()

    print(len(antinode_coordinates))

import sys
from collections import defaultdict
from itertools import combinations
from pathlib import Path


def get_antinodes(
    antenna1: tuple[int, int], antenna2: tuple[int, int]
) -> list[tuple[int, int]]:
    (x1, y1) = antenna1
    (x2, y2) = antenna2

    dist_x = abs(x2 - x1)
    if x1 <= x2:
        a1, a2 = x1 - dist_x, x2 + dist_x
    else:
        a1, a2 = x1 + dist_x, x2 - dist_x

    dist_y = abs(y2 - y1)
    if y1 <= y2:
        b1, b2 = y1 - dist_y, y2 + dist_y
    else:
        b1, b2 = y1 + dist_y, y2 - dist_y

    return [(a1, b1), (a2, b2)]


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python part1.py input.txt")
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
            for x, y in get_antinodes(antenna1, antenna2):
                if 0 <= x < gridwidth and 0 <= y < gridheight:
                    grid[y][x] = "#"
                    antinode_coordinates.add((x, y))

    # for line in grid:
    #     print("".join(line))
    # print()

    print(len(antinode_coordinates))

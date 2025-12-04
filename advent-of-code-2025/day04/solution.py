import sys
from copy import deepcopy
from itertools import product
from pathlib import Path


def part1(input: list[list[str]]) -> int:
    return remove_rolls(input)


def part2(input: list[list[str]]) -> int:
    result = 0
    while removed_rolls := remove_rolls(input):
        result += removed_rolls
    return result


def remove_rolls(input: list[list[str]]) -> int:
    result = 0
    removed_rolls: list[tuple[int, int]] = []
    for rx, row in enumerate(input):
        for cx, col in enumerate(row):
            if col != "@":
                continue
            adjacent_rolls = 0
            for rs, cs in product((-1, 0, 1), repeat=2):
                if rs == 0 and cs == 0:
                    continue
                rx1 = rx + rs
                cx1 = cx + cs
                if rx1 < 0 or rx1 == len(row) or cx1 < 0 or cx1 == len(input):
                    continue
                if input[rx1][cx1] == "@":
                    adjacent_rolls += 1
            if adjacent_rolls < 4:
                removed_rolls.append((rx, cx))
                result += 1
    for rx, cx in removed_rolls:
        input[rx][cx] = "x"
    # for row in input:
    #     print("".join(row))
    # print()
    return result


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} input.txt")
        sys.exit(1)
    input_file = Path(sys.argv[1])
    with open(input_file, "r") as f:
        input = f.readlines()
    input = [list(line.strip()) for line in input]
    print(part1(deepcopy(input)))
    print(part2(input))

import sys
from pathlib import Path


def part1(input: list[str]):
    dial = 50
    result = 0
    for line in input:
        dial += (-1 if line[0] == "L" else 1) * int(line[1:])
        dial %= 100
        if dial == 0:
            result += 1
    return result


def part2(input: list[str]):
    dial = 50
    result = 0
    for line in input:
        direction = -1 if line[0] == "L" else 1
        rotation = int(line[1:])
        result += rotation // 100
        if dial != 0:
            new_dial = dial + direction * (rotation % 100)
            if (dial > 0 and new_dial < 0) or new_dial == 0 or new_dial >= 100:
                result += 1
        dial = (dial + direction * rotation) % 100
    return result


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} input.txt")
        sys.exit(1)
    input_file = Path(sys.argv[1])
    with open(input_file, "r") as f:
        input = f.readlines()
    print(part1(input))
    print(part2(input))

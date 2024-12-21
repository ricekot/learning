from functools import cache
import sys
from pathlib import Path


@cache
def process_stone(stone, n) -> int:
    if n == 0:
        return 1
    if stone == "0":
        return process_stone("1", n - 1)
    if len(stone) % 2 == 0:
        return process_stone(stone[0 : len(stone) // 2], n - 1) + process_stone(
            str(int(stone[len(stone) // 2 :])), n - 1
        )
    else:
        return process_stone(str(int(stone) * 2024), n - 1)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python part1.py input.txt")
        sys.exit(1)

    input_file = Path(sys.argv[1])
    with open(input_file, "r") as f:
        stones = f.readline().strip().split()

    print(sum(map(lambda stone: process_stone(stone, 75), stones)))

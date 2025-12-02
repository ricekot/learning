import sys
from pathlib import Path


def part1(input: list[str]):
    result = 0
    for r in input:
        limits = r.partition("-")
        for id in range(int(limits[0]), int(limits[2]) + 1):
            id = str(id)
            if len(id) % 2 == 0 and id[: len(id) // 2] == id[len(id) // 2 :]:
                result += int(id)
    return result


def part2(input: list[str]):
    result = 0
    for r in input:
        limits = r.partition("-")
        for id in range(int(limits[0]), int(limits[2]) + 1):
            id = str(id)
            for i in range(1, len(id)):
                if len(id) % i == 0 and id == id[0:i] * (len(id) // i):
                    result += int(id)
                    break
    return result


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} input.txt")
        sys.exit(1)
    input_file = Path(sys.argv[1])
    with open(input_file, "r") as f:
        input = f.readline().split(",")
    print(part1(input))
    print(part2(input))

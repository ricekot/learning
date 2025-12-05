import sys
from pathlib import Path


def part1(ranges: list[tuple[int, int]], ids: list[int]) -> int:
    result = 0
    for id in ids:
        if any(low <= id <= high for low, high in ranges):
            result += 1
    return result


def part2(ranges: list[tuple[int, int]]) -> int:
    sorted_ranges = sorted(ranges, key=lambda r: r[0])
    i = 0
    while i < len(sorted_ranges) - 1:
        if sorted_ranges[i][1] >= sorted_ranges[i + 1][0]:
            new_range = (
                sorted_ranges[i][0],
                max(sorted_ranges[i][1], sorted_ranges[i + 1][1]),
            )
            del sorted_ranges[i : i + 2]
            sorted_ranges.insert(i, new_range)
        else:
            i += 1

    result = 0
    for r in sorted_ranges:
        result += r[1] - r[0] + 1
    return result


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} input.txt")
        sys.exit(1)
    input_file = Path(sys.argv[1])
    ranges = []
    ids = []
    with open(input_file, "r") as f:
        while line := f.readline():
            if not line.strip():
                continue
            elif "-" in line:
                ranges.append(tuple(map(lambda x: int(x), line.split("-"))))
            else:
                ids.append(int(line))
    print(part1(ranges, ids))
    print(part2(ranges))

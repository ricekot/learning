import sys
from functools import cache
from pathlib import Path


def part1(manifold: list[str]) -> int:
    start = manifold[0]
    beam_pos = [0] * len(start)
    beam_pos[start.find("S")] = 1
    result = 0
    for line in manifold[1:]:
        splitter = -1
        while (splitter := line.find("^", splitter + 1)) != -1:
            if beam_pos[splitter] == 1:
                result += 1
                beam_pos[splitter] = 0
                beam_pos[splitter - 1] = 1
                beam_pos[splitter + 1] = 1
    return result


def part2(manifold: list[str]) -> int:
    @cache
    def process(manifold_start: int, beam_pos: int):
        for idx, line in enumerate(manifold[manifold_start:], start=manifold_start):
            splitter = -1
            while (splitter := line.find("^", splitter + 1)) != -1:
                if splitter == beam_pos:
                    return process(idx + 1, beam_pos - 1) + process(
                        idx + 1, beam_pos + 1
                    )
        return 1

    return process(1, manifold[0].find("S"))


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} input.txt")
        sys.exit(1)
    input_file = Path(sys.argv[1])
    with open(input_file, "r") as f:
        input = f.readlines()
    input = [line.strip() for line in input]
    print(part1(input))
    print(part2(input))

import sys
from itertools import product
from multiprocessing import Pool
from pathlib import Path


def check_line(line: str) -> int:
    lhs, rhs = line.split(": ")
    lhs = int(lhs)
    rhs = list(map(lambda x: int(x), rhs.strip().split()))
    return lhs if check_equation(lhs, rhs) else 0


def check_equation(lhs: int, rhs: list[int]) -> bool:
    for operator_permutation in product("*+|", repeat=len(rhs) - 1):
        result = rhs[0]
        for num, operator in zip(rhs[1:], operator_permutation, strict=True):
            match operator:
                case "*":
                    result *= num
                case "+":
                    result += num
                case "|":
                    result = int(f"{result}{num}")
            if result > lhs:
                break
        if result == lhs:
            return True
    return False


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python part2.py input.txt")
        sys.exit(1)

    input_file = Path(sys.argv[1])

    with open(input_file, "r") as f:
        result = 0
        count = 0
        lines = f.readlines()

    with Pool() as pool:
        result = 0
        for line_result in pool.imap_unordered(check_line, lines):
            result += line_result
        print(result)

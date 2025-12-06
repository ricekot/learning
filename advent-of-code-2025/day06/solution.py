import sys
from functools import reduce
from pathlib import Path


def part1(input: list[str]) -> int:
    operators: list[str] = []
    operands: list[list[int]] = []
    for line in input:
        line = line.strip()
        if "*" in line or "+" in line:
            operators = line.split()
        else:
            operands.append(list(map(lambda x: int(x), line.split())))
    result = 0
    for i, operator in enumerate(operators):
        problem_result = 0 if operator == "+" else 1
        for j in range(len(operands)):
            if operator == "+":
                problem_result += operands[j][i]
            else:
                problem_result *= operands[j][i]
        result += problem_result
    return result


def part2(input: list[str]) -> int:
    result = 0
    operands = []
    for col in reversed(range(len(input[0]))):
        number = ""
        for row in range(0, len(input) - 1):
            if (digit := input[row][col]) != " " and digit != "\n":
                number += digit
        if number:
            operands.append(int(number))
        if input[-1][col] == "*":
            result += reduce(lambda x, y: x * y, operands)
            operands.clear()
        elif input[-1][col] == "+":
            result += sum(operands)
            operands.clear()
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

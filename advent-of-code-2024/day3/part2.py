from pathlib import Path
import re
import sys

if len(sys.argv) != 2:
    print("Usage: python part1.py input.txt")
    sys.exit(1)

input_file = Path(sys.argv[1])

with open(input_file, "r") as f:
    program = "".join(f.readlines())

result = 0
enabled = True
for match in re.finditer(
    r"(mul\((?P<num1>\d+),(?P<num2>\d+)\))|do\(\)|don't\(\)", program
):
    if match.group(0) == "do()":
        enabled = True
    elif match.group(0) == "don't()":
        enabled = False
    elif enabled:
        num1 = int(match.group("num1"))
        num2 = int(match.group("num2"))
        result += num1 * num2

print(result)

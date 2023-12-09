import re
import sys

if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} <input file>")
    exit(1)

with open(sys.argv[1], "r") as f:
    lines = f.readlines()
    # dictionary of index of star to a list of adjacent part numbers
    stars: dict[tuple, list] = {}
    for idx, line in enumerate(lines):
        line = line.strip()
        numbers = re.findall(r"\d+", line)
        end_idx = 0
        for number in numbers:
            previous_line = lines[idx - 1].strip() if idx > 0 else "." * len(line)
            next_line = (
                lines[idx + 1].strip() if (idx < len(lines) - 1) else "." * len(line)
            )
            number_idx = line.index(number, end_idx)
            start_idx = (number_idx - 1) if number_idx > 0 else 0
            end_idx = (
                (number_idx + len(number) + 1) if number_idx < len(line) else len(line)
            )
            for m in re.finditer(r"\*", previous_line[start_idx:end_idx]):
                stars.setdefault((m.start() + start_idx, idx - 1), []).append(number)
            for m in re.finditer(r"\*", next_line[start_idx:end_idx]):
                stars.setdefault((m.start() + start_idx, idx + 1), []).append(number)
            if number_idx > 0:
                if line[number_idx - 1] == "*":
                    stars.setdefault((number_idx - 1, idx), []).append(number)
            if number_idx + len(number) < len(line):
                if line[number_idx + len(number)] == "*":
                    stars.setdefault((number_idx + len(number), idx), []).append(number)

    result = 0
    for numbers in stars.values():
        if len(numbers) == 2:
            result += int(numbers[0]) * int(numbers[1])

print(result)

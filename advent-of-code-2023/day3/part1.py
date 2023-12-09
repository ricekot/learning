import re
import sys

if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} <input file>")
    exit(1)

with open(sys.argv[1], "r") as f:
    lines = f.readlines()
    result = 0
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
            search_string = previous_line[start_idx:end_idx]
            search_string += next_line[start_idx:end_idx]
            if number_idx > 0:
                search_string += line[number_idx - 1]
            if number_idx + len(number) < len(line):
                search_string += line[number_idx + len(number)]
            if re.search(r"[^\.\d]", search_string) is not None:
                result += int(number)

print(result)

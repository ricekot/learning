from pathlib import Path
import sys

if len(sys.argv) != 2:
    print("Usage: python part2.py input.txt")
    sys.exit(1)

input_file = Path(sys.argv[1])

with open(input_file, "r") as f:
    reports = f.readlines()

safe_report_count = 0
for report in reports:
    levels = list(map(int, report.split()))
    is_increasing = False
    is_decreasing = False

    for i in range(len(levels) - 1):
        if levels[i] < levels[i + 1]:
            is_increasing = True
        elif levels[i] > levels[i + 1]:
            is_decreasing = True
        else:
            break
        if is_increasing and is_decreasing:
            break
        diff = abs(levels[i] - levels[i + 1])
        if diff < 1 or diff > 3:
            break
    else:
        safe_report_count += 1

print(safe_report_count)

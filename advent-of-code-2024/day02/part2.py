from pathlib import Path
import sys


def check_report(levels: list[int], retry: bool) -> bool:
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
        return True

    if retry:
        for j in range(max(0, i - 1), i + 2):
            new_levels = levels[:j] + levels[j + 1 :]
            if check_report(new_levels, False):
                return True
    return False


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python part2.py input.txt")
        sys.exit(1)

    input_file = Path(sys.argv[1])

    with open(input_file, "r") as f:
        reports = f.readlines()

    safe_report_count = 0
    for report in reports:
        levels = list(map(int, report.split()))
        if check_report(levels, True):
            safe_report_count += 1

    print(safe_report_count)

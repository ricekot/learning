from functools import cmp_to_key
from pathlib import Path
import sys

if len(sys.argv) != 2:
    print("Usage: python part2.py input.txt")
    sys.exit(1)

input_file = Path(sys.argv[1])
page_ordering_rules = set()

with open(input_file, "r") as f:
    page_updates = []
    for line in f.readlines():
        if "|" in line:
            page_ordering_rules.add(line.strip())
        elif line != "\n":
            page_updates.append(line.strip())

    def comparator(num1, num2):
        if f"{num1}|{num2}" in page_ordering_rules:
            return -1
        return 1

    result = 0
    for update in page_updates:
        nums = list(map(lambda x: int(x), update.split(",")))
        sorted_nums = sorted(nums, key=cmp_to_key(comparator))
        if nums != sorted_nums:
            result += sorted_nums[len(nums) // 2]
    print(result)

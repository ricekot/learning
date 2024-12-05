from pathlib import Path
import sys

if len(sys.argv) != 2:
    print("Usage: python part1.py input.txt")
    sys.exit(1)

input_file = Path(sys.argv[1])

with open(input_file, "r") as f:
    lines = f.readlines()
    nums1 = []
    nums2 = []
    for line in lines:
        nums = line.split()
        nums1.append(int(nums[0]))
        nums2.append(int(nums[1]))

    nums1.sort()
    nums2.sort()

    result = sum([abs(a - b) for a, b in zip(nums1, nums2)])

    print(result)

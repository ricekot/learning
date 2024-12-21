from pathlib import Path
import sys

if len(sys.argv) != 2:
    print("Usage: python part2.py input.txt")
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

    cache = {}
    result = 0
    for i in range(len(nums1)):
        n = nums1[i]
        if n in cache:
            result += cache[n]
            continue
        similarity_score = n * len(list(filter(lambda x: x == n, nums2)))
        cache[n] = similarity_score
        result += similarity_score

    print(result)

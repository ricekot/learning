import sys
from pathlib import Path

if len(sys.argv) != 2:
    print("Usage: python part1.py input.txt")
    sys.exit(1)

input_file = Path(sys.argv[1])
with open(input_file, "r") as f:
    disk_map = list(map(lambda x: int(x), f.readline().strip()))

id_number = 0
blocks = []
for idx, digit in enumerate(disk_map):
    if idx % 2 == 0:
        for i in range(digit):
            blocks.append(("file", id_number))
        id_number += 1
    else:
        for i in range(digit):
            blocks.append(("free"))

result = 0
idx = 0
while blocks:
    first = blocks.pop(0)
    if first[0] == "file":
        result += idx * int(first[1])
    else:
        if not blocks:
            break
        last = blocks.pop()
        while not last[0] == "file":
            if not blocks:
                break
            last = blocks.pop()
        else:
            result += idx * int(last[1])
    idx += 1

print(result)

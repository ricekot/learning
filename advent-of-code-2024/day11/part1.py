import sys
from pathlib import Path

if len(sys.argv) != 2:
    print("Usage: python part1.py input.txt")
    sys.exit(1)

input_file = Path(sys.argv[1])
with open(input_file, "r") as f:
    stones = f.readline().strip().split()

# print(f"Initial arrangement:\n{' '.join(stones)}\n")

blink_count = 25

for count in range(blink_count):
    new_stones = []
    for stone in stones:
        if stone == "0":
            new_stones.append("1")
        elif len(stone) % 2 == 0:
            new_stones.append(stone[0 : len(stone) // 2])
            new_stones.append(str(int(stone[len(stone) // 2 :])))
        else:
            new_stones.append(str(int(stone) * 2024))
    stones = new_stones
    # print(f"After {count + 1} blink{'s' if count > 0 else ''}:\n{' '.join(stones)}\n")

print(len(stones))

from pathlib import Path
import re
import sys

if len(sys.argv) != 2:
    print("Usage: python part1.py input.txt")
    sys.exit(1)

input_file = Path(sys.argv[1])

with open(input_file, "r") as f:
    word_search = f.readlines()

height = len(word_search)
width = len(word_search[0])

count = 0
for y in range(0, height):
    for x in range(0, width):
        if word_search[y][x] != "X":
            continue
        # left to right
        if word_search[y][x : x + 4] == "XMAS":
            count += 1
        # right to left
        if (
            x - 3 >= 0
            and "".join([word_search[y][x - i] for i in range(0, 4)]) == "XMAS"
        ):
            count += 1
        # top to bottom
        if (
            y + 3 < height
            and "".join([word_search[y + i][x] for i in range(0, 4)]) == "XMAS"
        ):
            count += 1
        # bottom to top
        if (
            y - 3 >= 0
            and "".join([word_search[y - i][x] for i in range(0, 4)]) == "XMAS"
        ):
            count += 1
        # top left to bottom right
        if (
            x + 3 < width
            and y + 3 < height
            and "".join([word_search[y + i][x + i] for i in range(0, 4)]) == "XMAS"
        ):
            count += 1
        # bottom right to top left
        if (
            x - 3 >= 0
            and y - 3 >= 0
            and "".join([word_search[y - i][x - i] for i in range(0, 4)]) == "XMAS"
        ):
            count += 1
        # top right to bottom left
        if (
            x - 3 >= 0
            and y + 3 < height
            and "".join([word_search[y + i][x - i] for i in range(0, 4)]) == "XMAS"
        ):
            count += 1
        # bottom left to top right
        if (
            x + 3 < width
            and y - 3 >= 0
            and "".join([word_search[y - i][x + i] for i in range(0, 4)]) == "XMAS"
        ):
            count += 1

print(count)

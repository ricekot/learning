from pathlib import Path
import re
import sys

if len(sys.argv) != 2:
    print("Usage: python part2.py input.txt")
    sys.exit(1)

input_file = Path(sys.argv[1])

with open(input_file, "r") as f:
    word_search = f.readlines()

height = len(word_search)
width = len(word_search[0])

count = 0
for y in range(0, height):
    for x in range(0, width):
        if word_search[y][x] in {"M", "S"} and x + 2 < width and y + 2 < height:
            top_to_bottom = "".join([word_search[y + i][x + i] for i in range(0, 3)])
            bottom_to_top = "".join(
                [word_search[y + 2 - i][x + i] for i in range(0, 3)]
            )
            if all(map(lambda x: x in {"MAS", "SAM"}, {top_to_bottom, bottom_to_top})):
                count += 1

print(count)

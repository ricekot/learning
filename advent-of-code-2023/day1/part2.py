from pathlib import Path

NAMES_TO_DIGITS = {
    "one": 1,
    "two": 2,
    "three": 3,
    "four": 4,
    "five": 5,
    "six": 6,
    "seven": 7,
    "eight": 8,
    "nine": 9,
}


def get_first_digit(line: str):
    for index, char in enumerate(line):
        if char.isdigit():
            first_digit = int(char)
            break

    first_name = ""
    for name in NAMES_TO_DIGITS:
        if name in line and (name_index := line.index(name)) < index:
            index = name_index
            first_name = name

    if first_name != "":
        first_digit = NAMES_TO_DIGITS[first_name]

    return first_digit


def get_last_digit(line: str):
    for index, char in enumerate(line[::-1]):
        if char.isdigit():
            last_digit = int(char)
            break
    index = len(line) - index - 1
    
    last_name = ""    
    for name in NAMES_TO_DIGITS:
        if name in line and (name_index := line.rindex(name)) > index:
            index = name_index
            last_name = name
    if last_name != "":
        last_digit = NAMES_TO_DIGITS[last_name]
    
    return last_digit


with open(Path(__file__).parent / "input.txt", "r") as f:
    lines = f.readlines()
    result = 0
    for line in lines:
        result += get_first_digit(line) * 10 + get_last_digit(line)
print(result)

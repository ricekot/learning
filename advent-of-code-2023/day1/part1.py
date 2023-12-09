from pathlib import Path

with open(Path(__file__).parent / "input.txt", "r") as f:
    lines = f.readlines()
    result = 0
    for line in lines:
        for char in line:
            if char.isdigit():
                first_digit = int(char)
                break
        for char in line[::-1]:
            if char.isdigit():
                last_digit = int(char)
                break
        result += first_digit * 10 + last_digit
print(result)

import sys
from pathlib import Path


def part1(input: list[str]) -> int:
    result = 0
    for bank in input:
        sorted_bank = sorted(bank)
        biggest = sorted_bank[-1]
        if biggest == bank[-1]:
            joltage = 10 * int(sorted_bank[-2]) + int(biggest)
        else:
            joltage = 10 * int(biggest) + int(
                sorted(bank[bank.find(biggest) + 1 :])[-1]
            )
        result += joltage
    return result


def part2(input: list[str]):
    def find_biggest_with_n_elements_after_it(arr: str, n: int):
        if len(arr) <= n:
            raise ValueError("Invalid input")
        sorted_arr = sorted(arr)
        while sorted_arr:
            biggest = sorted_arr.pop()
            if len(arr) - arr.find(biggest) > n:
                return biggest
        raise ValueError("Impossible")

    result = 0
    for bank in input:
        joltage = 0
        for n in reversed(range(12)):
            digit = find_biggest_with_n_elements_after_it(bank, n)
            joltage += 10**n * int(digit)
            bank = bank[bank.find(digit) + 1 :]
        result += joltage
    return result


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} input.txt")
        sys.exit(1)
    input_file = Path(sys.argv[1])
    with open(input_file, "r") as f:
        input = f.readlines()
    input = [line.strip() for line in input]
    print(part1(input))
    print(part2(input))

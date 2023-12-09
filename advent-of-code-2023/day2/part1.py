from pathlib import Path
import sys

class CubeSet:
    red: int = 0
    green: int = 0
    blue: int = 0


class Game:
    id: int
    cube_sets: list[CubeSet]


MAX_CUBE_SET = CubeSet()
MAX_CUBE_SET.red = 12
MAX_CUBE_SET.green = 13
MAX_CUBE_SET.blue = 14

def parse_line(line: str) -> Game:
    id = int(line.partition(":")[0].partition(" ")[2])
    cube_sets_str = line.partition(":")[2].strip()
    cube_sets = []
    for cube_set_str in cube_sets_str.split(";"):
        cube_set = CubeSet()
        for cube in cube_set_str.strip().split(","):
            count, colour = cube.strip().split(" ")
            count = int(count)
            match colour:
                case "red":
                    cube_set.red = count
                case "green":
                    cube_set.green = count
                case "blue":
                    cube_set.blue = count
                case _:
                    raise ValueError(f"Unexpected colour: {colour}")
        cube_sets.append(cube_set)
    result = Game()
    result.id = id
    result.cube_sets = cube_sets
    return result

if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} <input file>")
    exit(1)

with open(Path(__file__).parent / sys.argv[1], "r") as f:
    lines = f.readlines()
    result = 0
    for line in lines:
        game = parse_line(line)
        possible = True
        for cube_set in game.cube_sets:
            if cube_set.red > MAX_CUBE_SET.red or cube_set.green > MAX_CUBE_SET.green or cube_set.blue > MAX_CUBE_SET.blue:
                possible = False
                break
        if possible:
            result += game.id

print(result)

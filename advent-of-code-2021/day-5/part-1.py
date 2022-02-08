import sys

if len(sys.argv) < 2:
    exit(1)

with open(sys.argv[1], 'r') as input:
    line_count = sum(1 for line in input)
    grid = [[0 for i in range(1000)] for j in range(1000)]
    input.seek(0)
    for line in input:
        x1 = int(line[:line.index(',')])
        y1 = int(line[line.index(',')+1:line.index('-')])
        x2 = int(line[line.index('>')+1:line.rindex(',')])
        y2 = int(line[line.rindex(',') + 1:])
        if x1 == x2:
            yl, yu = (y1, y2) if y1 < y2 else (y2, y1)
            for y in range(yl, yu+1):
                grid[x1][y] += 1
        elif y1 == y2:
            xl, xu = (x1, x2) if x1 < x2 else (x2, x1)
            for x in range(xl, xu+1):
                grid[x][y1] += 1
    res = 0
    for row in grid:
        for val in row:
            if val >= 2:
                res += 1
    print(res)

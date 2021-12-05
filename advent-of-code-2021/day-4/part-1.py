import sys
import numpy as np

if len(sys.argv) < 2:
    exit(1)


def bingo(matrix):
    matrix = np.array(matrix)
    for i in range(len(matrix)):
        rows_win = (matrix[i, :] == '-1').all()
        cols_win = (matrix[:, i] == '-1').all()
        if rows_win or cols_win:
            return True
    return False


with open(sys.argv[1], 'r') as input:
    bingo_numbers = next(input).strip().split(',')
    matrices = list(list(list()))
    while next(input, None):
        matrix = list(list())
        for i in range(5):
            matrix.append(next(input).split())
        matrices.append(matrix)

    matrices = np.array(matrices)
    for x in bingo_numbers:
        matrices[matrices == x] = '-1'
        for matrix in matrices:
            if (bingo(matrix)):
                matrix[matrix == '-1'] = 0
                print(matrix.astype(int).sum() * int(x))
                exit(0)

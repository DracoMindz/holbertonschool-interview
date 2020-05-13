#!/usr/bin/python3
"""
N queens puzzle challenge
"""

import sys


def solutionprint(board):
    """
    print solution to NQueens
    :param board: matrix, list of lists
    :return: solution
    """
    solNQ = []
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 1:
                solNQ.append([i, j])
    print(solNQ)


def safeSpot(board, row, col, N):
    """
    Check if Queen is in  safe space
    """
    # check row on left side
    for idx_i in range(col):
        if board[row][idx_i] == 1:
            return False

        # check diagonal upper
    for idx_i, idx_j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[idx_i][idx_j] == 1:
            return False

    # check diagnol lower
    for idx_i, idx_j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[idx_i][idx_j] == 1:
            return False
    return True


def bestPlace(board, col, N):
    """
    if all queens are placed, best place to place
    :param board: list of lists
    :param col: possible location
    :return: true or false
    """

    if col == N:
        solutionprint(board)
        return True

    # if is a safe Spot place the queen
    safe = False
    for index in range(N):
        if safeSpot(board, index, col, N):
            board[index][col] = 1
            safe = bestPlace(board, col + 1, N) or safe

            # no safe place remove Queen from board
            board[index][col] = 0
    return safe


if __name__ == "__main__":
    """
    N is number of Queens to be placed
    NxN are dimeanions for chess board
    exit and null cases
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # N value introduced using try except
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    # chess board, shape(N, N)
    board = [[0 for i in range(N)] for j in range(N)]
    bestPlace(board, 0, N)

#!/usr/bin/python3

""" contains rotate_2d_matrix funct"""


def rotate_2d_matrix(mat):
    """ Given an n x n 2D matrix, rotate it 90 degrees clockwise."""
    for i in range(len(mat)):
        for j in range(i + 1, len(mat)):
            mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
    for i in range(len(mat)):
        mat[i].reverse()

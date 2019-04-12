/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** condition_move
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "maze.h"
#include "my.h"

int check_right(maze_t *maze, int *x, int *y)
{
    if (*y < maze->cols - 1 && IS_WALL(maze->map[*x][*y + 1]) == 0) {
        (*y)++;
        return (1);
    }
    return (0);
}

int check_down(maze_t *maze, int *x, int *y)
{
    if (*x < maze->rows - 1 && *y <= maze->cols - 1 &&
        (maze->map[*x][*y + 1] == '\0' ||
        IS_WALL(maze->map[*x][*y + 1]) == 1) &&
        (*x == 0 || IS_WALL(maze->map[*x - 1][*y]) == 1) &&
        IS_WALL(maze->map[*x + 1][*y]) == 0) {
        (*x)++;
        return (1);
    }
    return (0);
}

int check_left(maze_t *maze, int *x, int *y)
{
    if (*y >= 0 && *x < maze->rows - 1 && *y <= maze->cols - 1 &&
        (*x >= 0 || IS_WALL(maze->map[*x - 1][*y]) == 1) &&
        (maze->map[*x][*y + 1] == '\0' ||
        IS_WALL(maze->map[*x][*y + 1]) == 1) &&
        IS_WALL(maze->map[*x + 1][*y]) == 1) {
        (*y)--;
        return (1);
    }
    return (0);
}

int check_top(maze_t *maze, int *x, int *y)
{
    if (*x < maze->rows - 1 && *y < maze->cols - 1 && *y != 0 &&
        IS_WALL(maze->map[*x + 1][*y]) == 1 &&
        IS_WALL(maze->map[*x][*y + 1]) == 1 &&
        IS_WALL(maze->map[*x][*y - 1]) == 1) {
        (*x)--;
        return (1);
    }
    return (0);
}
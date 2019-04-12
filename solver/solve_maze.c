/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solve_maze
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "maze.h"
#include "my.h"

void disp_maze(maze_t *maze)
{
    for (int i = 0; maze->map[i] != NULL; i++) {
        write(1, maze->map[i], maze->cols);
        if (maze->map[i + 1] != NULL)
            write(1, "\n", 1);
    }
}

void free_maze(maze_t *maze)
{
    for (int i = 0; maze->map[i] != NULL; i++)
        free(maze->map[i]);
    free(maze->map);
    free(maze);
}

int check_move(maze_t *maze, int *x, int *y)
{
    if (*y < maze->cols - 1 && IS_WALL(maze->map[*x][*y + 1]) == 0) {
        (*y)++;
        return (0);
    }
    if (*x < maze->rows - 1 && *y <= maze->cols - 1 && (maze->map[*x][*y + 1] == '\0' || IS_WALL(maze->map[*x][*y + 1]) == 1) &&
        (*x == 0 || IS_WALL(maze->map[*x - 1][*y]) == 1) && IS_WALL(maze->map[*x + 1][*y]) == 0) {
        (*x)++;
        return (0);
    }
    if (*y >= 0 && *x < maze->rows - 1 && *y <= maze->cols - 1 && (*x >= 0 || IS_WALL(maze->map[*x - 1][*y]) == 1) &&
        (maze->map[*x][*y + 1] == '\0' || IS_WALL(maze->map[*x][*y + 1]) == 1) && IS_WALL(maze->map[*x + 1][*y]) == 1) {
        (*y)--;
        return (0);
    }
    if (*x < maze->rows - 1 && *y < maze->cols - 1 && *y != 0 && IS_WALL(maze->map[*x + 1][*y]) == 1 &&
        IS_WALL(maze->map[*x][*y + 1]) == 1 && IS_WALL(maze->map[*x][*y - 1]) == 1) {
        (*x)--;
        return (0);
    }
    if (*x + 1 <= maze->rows - 1 && IS_WALL(maze->map[*x + 1][*y]) == 0) {
        (*x)++;
        return (0);
    }
    return(84);
}

void solve_maze(maze_t *maze)
{
    int x = 0;
    int y = 0;
    int count = 0;

    for (; count < 50000; count++) {
        maze->map[x][y] = 'o';
        if (x == maze->rows - 1 && y == maze->cols - 1) {
            disp_maze(maze);
            free_maze(maze);
            exit(0);
        }
        else {
            if (check_move(maze, &x, &y) == 84) {
                free_maze(maze);
                exit(84);
            }
        }
    }
    exit(84);
}
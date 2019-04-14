/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#define IS_WALL(c) ((c == 'X' || c == 'o' || c == 'a') ? 1 : 0)

#include "maze.h"

char *get_file(char **argv);
void create_maze(char **argv);
int count_rows(char *str);
int count_cols(char *str);
void solve_maze(maze_t *maze);
int check_right(maze_t *maze, int *x, int *y);
int check_down(maze_t *maze, int *x, int *y);
int check_left(maze_t *maze, int *x, int *y);
int check_top(maze_t *maze, int *x, int *y);
#endif /* !MY_H_ */

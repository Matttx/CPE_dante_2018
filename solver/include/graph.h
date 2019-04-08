/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** graph
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include "maze.h"

typedef struct graph_s
{
    int **matrix;
    int **nbr;
}graph_t;

void create_graph(maze_t *maze);
#endif /* !GRAPH_H_ */

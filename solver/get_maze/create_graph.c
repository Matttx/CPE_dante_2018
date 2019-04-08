/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** create_graph
*/

#include "my.h"
#include "graph.h"
#include "maze.h"
#include <stdio.h>
#include <stdlib.h>

void create_graph(maze_t *maze)
{
    graph_t *graph = malloc(sizeof(graph_t));
    int nb = 0;

    graph->nbr = malloc(sizeof(int *) * (maze->rows + 1));
    for (int i = 0; i < maze->rows; i++) {
        graph->nbr[i] = malloc(sizeof(int) * (maze->cols + 1));
        for (int j = 0; j < maze->cols; j++) {
            graph->nbr[i][j] = nb;
            nb++;
        }
    }
    graph->matrix = malloc(sizeof(int *) * (maze->size + 1));
    for (int i = 0; i < maze->size; i++) {
        graph->matrix[i] = malloc(sizeof(int) * (maze->size + 1));
        for (int j = 0; j < maze->size; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
           printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
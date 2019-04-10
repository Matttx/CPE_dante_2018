/*
** EPITECH PROJECT, 2018
** create_path.c
** File description:
** No description
*/

#include "my.h"
#include <stdlib.h>

char **handle_random(char **map, int *i, int *j)
{
    int cond = 0;

    cond = rand() % 2;
    map[*i][*j] = '*';
    if (cond == 0) {
        if (*j - 1 > 0) {
            map[*i][*j - 1] = '*';
            map[*i][*j - 2] = '*';
        }
        *j -= 2;
    }
    if (cond == 1) {
        if (*i - 1 >= 0) {
            map[*i - 1][*j] = '*';
            map[*i - 2][*j] = '*';
            (*j) -= 2;
        }
    }
    return (map);
}

char **create_path(char **map, int x, int y)
{
    int i = y - 1;
    int j = x - 1;

    if (y % 2 == 0)
        i -= 1;
    for (; i >= 0; i -= 2) {
        while (j >= 0) {
            map = handle_random(map, &i, &j);
        }
        j = x - 1;
    }
    for (int f = x - 1; f >= 0; f--)
        map[0][f] = '*';
/*     for (int f = y - 1; f >= 0; f--)
        map[f][0] = '*'; */
    return (map);
}
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
    if (cond == 0 && *j > 1) {
        for (int count = 0; *j - count >= 0 && count < 2; count++) {
            map[*i][*j - count] = '*';
        }
    }
    if (cond == 1 || *j <= 1) {
        if (*i - 1 >= 0) {
            map[*i - 1][*j] = '*';
            map[*i - 2][*j] = '*';
        }
    }
    return (map);
}

char **create_path(char **map, int x, int y)
{
    int i = y - 1;
    int min = 0;

    if (y % 2 == 0)
        i -= 1;
    if (x % 2 == 0)
        min = 1;
    else
        min = 0;
    for (; i >= 0; i -= 2) {
        for (int j = x - 1; j >= min; j -= 2)
            map = handle_random(map, &i, &j);
    }
    for (int f = x - 1; f >= 0; f--)
        map[0][f] = '*';
    return (map);
}
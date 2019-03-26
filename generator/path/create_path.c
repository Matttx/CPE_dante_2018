/*
** EPITECH PROJECT, 2018
** create_path.c
** File description:
** No description
*/

#include "my.h"
#include <stdlib.h>

int random_function(char **map, int *i, int *j)
{
    int random = 0;

    if (*i == 0 && *j == 0) return (0);
    if (map[*i][*j] == '*' && *i == 0) {
        map[*i][*j - 1] = '*';
    } if (map[*i][*j] == '*') {
        random = rand() % 2 + 1;
        if (random == 1 && *j != 0)
            map[*i][*j - 1] = '*';
        else if (random == 2 && *i != 0)
            map[*i - 1][*j] = '*';
    } if (map[*i][*j] == 'X') {
        random = rand() % 4 + 1;
        if (random == 1 && *j != 0)
            map[*i][*j - 1] = '*';
        else if (random == 2 && *i != 0)
            map[*i - 1][*j] = '*';
    }
    return (0);
}

char **create_path(char **map, int x, int y)
{
    int i = y - 1;
    int j = x - 1;

    for (; i >= 0; i--) {
        for (j = x - 1; j >= 0; j--) {
            random_function(map, &i, &j);
        }
    }
    return (map);
}
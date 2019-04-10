/*
** EPITECH PROJECT, 2018
** map_generator.c
** File description:
** No description
*/

#include <stdlib.h>

char **fill_map(int x, int y, char **map)
{
    int j = 0;
    int i = 0;

    for (; i < y; i++) {
        for (j = 0; j < x; j++) {
            if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1))
                map[i][j] = '*';
            else
                map[i][j] = 'X';
        }
        map[i][j] = '\0';
    }
    return (map);
}

char **map_generator(int x, int y)
{
    char **map = NULL;
    int i = 0;

    map = malloc(sizeof(char *) * (y + 1));
    if (map == NULL)
        exit(84);
    for (; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        if (map[i] == NULL)
            exit(84);
    }
    map[i] = NULL;
    map = fill_map(x, y, map);
    return (map);
}
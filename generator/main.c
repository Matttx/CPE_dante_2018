/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** No description
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my.h"

void free_map(char **map, int y)
{
    for (int i = 0; i < y; i++) {
        free(map[i]);
    }
    free(map);
}

int main(int ac, char **av)
{
    char **map = NULL;
    if (ac != 4 && ac != 3) return (84);
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    srand(time(0));

    map = map_generator(x, y);
    map = create_path(map, x, y);
    for (int i = 0; map[i] != NULL; i++)
        printf("%s\n", map[i]);
    free_map(map, y);
    return (0);
}
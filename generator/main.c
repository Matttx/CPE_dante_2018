/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** No description
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
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
    if (ac == 3) {
        map = set_imperfect_map(map, x);
    }
    for (int i = 0; map[i] != NULL; i++) {
        write(1, map[i], y);
        if (map[i + 1] != NULL)
            write(1, "\n", 1);
    }
    free_map(map);
    return (0);
}
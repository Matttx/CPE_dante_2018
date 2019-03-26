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
    return (0);
}
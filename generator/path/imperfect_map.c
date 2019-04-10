/*
** EPITECH PROJECT, 2018
** imperfect_map.c
** File description:
** No description
*/

#include "my.h"

char **set_imperfect_map(char **map, int cols)
{
    map[1][cols - 1] = '*';
    map[1][cols - 2] = '*';
    return (map);
}
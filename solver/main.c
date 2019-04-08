/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "my.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    create_maze(argv);
    return (0);
}
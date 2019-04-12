/*
** EPITECH PROJECT, 2019
** count.c
** File description:
** count.c
*/

#include "my.h"
#include <stdlib.h>

int count_rows(char *str)
{
    int rows = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            rows++;
    }
    return (rows);
}

int check_cols(int cols, int tmp)
{
    static int i = 0;

    if (cols != tmp && i != 0)
        exit (84);
    else {
        i++;
        return (cols);
    }
}

int count_cols(char *str)
{
    int cols = 0;
    int tmp = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n')
            cols++;
        else if (str[i] == '\n') {
            tmp = check_cols(cols, tmp);
            cols = 0;
        }
    }
    return (tmp);
}
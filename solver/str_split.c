/*
** EPITECH PROJECT, 2018
** str_split.c
** File description:
** No description
*/

#include <stdlib.h>
#include "maze.h"

void get_size(char *str, maze_t *maze)
{
    int i = 0;

    for (int j = 0; str[j] != '\n'; j++, maze->cols++);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            maze->rows++;
    }
    if (str[i] == '\0' && str[i - 1] != '\n')
        maze->rows++;
}

static int spliter_count(char const *tab, char c)
{
    int i = 0;
    int words = 0;

    while (tab[i] != '\0') {
        words += (tab[i] != c && tab[i] != '\0');
        for (; tab[i] != '\0' && tab[i] != c ; i++);
        i++;
    }
    return (words);
}

char **str_split(char const *str, char c)
{
    char **args = NULL;
    int size = spliter_count(str, c);
    int i = 0;
    int k = 0;

    args = malloc(sizeof(char *) * (size + 1));
    for (int j = 0; j < size; j++) {
        for (k = 0 ; str[i + k] != c && str[i + k] != '\0' ; k++);
        args[j] = malloc(sizeof(char) * (k + 1));
        for (int l = 0; l < k; l++, i++)
            args[j][l] = str[i];
        args[j][k] = '\0';
        i++;
    }
    args[size] = NULL;
    return (args);
}
/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** get_maze
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "maze.h"
#include "my.h"

char **copy_map(char *str, char **map, maze_t *maze)
{
    int cols = 0;
    int rows = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            map[rows][cols] = '\0';
            rows++;
            cols = 0;
        } else if (rows == maze->rows - 1 && cols == maze->cols - 1) {
            map[rows][cols] = '\0';
            rows++;
            break;
        } else {
            map[rows][cols] = str[i];
            cols++;
        }
    }
    map[rows] = NULL;
    free(str);
    return (map);
}

char **create_map(char *str, maze_t *maze)
{
    int i = 0;
    char **map = NULL;

    maze->cols = count_cols(str);
    maze->rows = count_rows(str);
    maze->size = maze->cols * maze->rows;
    map = malloc(sizeof(char *) * (maze->rows + 1));
    if (map == NULL)
        return (NULL);
    for (; i < maze->rows; i++) {
        map[i] = malloc(sizeof(char) * (maze->cols + 1));
        if (map[i] == NULL)
            return (NULL);
    }
    map[i] = NULL;
    map = copy_map(str, map, maze);
    return (map);
}

char *get_file(char **argv)
{
    struct stat my_stat;
    int length = 0;
    char *str = NULL;
    int size = 0;
    int fd = 0;

    stat(argv[1], &my_stat);
    length = my_stat.st_size;
    str = malloc(sizeof(char) * (length + 1));
    fd = open(argv[1], O_RDONLY);
    size = read(fd, str, length);
    if (size == -1) {
        free(str);
        exit(84);
    }
    str[length] = '\0';
    return (str);
}

void create_maze(char **argv)
{
    char *file = NULL;
    maze_t *maze = malloc(sizeof(maze_t));

    file = get_file(argv);
    maze->map = str_split(file, '\n');
    solve_maze(maze);
}

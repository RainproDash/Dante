/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-vivien.boitard
** File description:
** error_management
*/

#include "header.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void error_management(int ac, char **av)
{
    int fd = 0;

    if (ac != 2)
        exit(84);
    if ((fd = open(av[1], O_RDONLY)) == -1) {
        close(fd);
        exit(84);
    }
}

void check_file(char **map)
{
    int len = strlen(map[0]);
    int i = 0;
    int my_len = 0;

    for (i = 0; map[i] != NULL; i++) {
        if ((my_len = strlen(map[i])) != len)
            exit(84);
        for (int j = 0; map[i][j] != '\0'; j++)
            (map[i][j] != '*' && map[i][j] != 'X') ? exit(84) : 0;
    }
}

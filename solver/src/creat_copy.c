/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-vivien.boitard
** File description:
** creat_copy
*/

#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int len_tab(char **map)
{
    int i = 0;

    for (; map[i] != NULL; i++);
    return i;
}

static void top_copy(char ***copy, int len)
{
    for (int i = 0; i < len + 2; i++)
        (*copy)[0][i] = 'X';
    (*copy)[0][len + 2] = '\0';
}

void creat_copy(char ***copy, char **map)
{
    int tab_len = len_tab(map);
    int len = strlen(map[0]);

    *copy = malloc(sizeof(char *) * (tab_len + 3));
    for (int i = 0; i < tab_len + 3; i++)
        (*copy)[i] = malloc(sizeof(char) * (len + 3));
    (*copy)[tab_len + 3] = NULL;
    top_copy(copy, len);
    for (int i = 0; i < tab_len; i++) {
        (*copy)[i + 1][0] = 'X';
        for (int j = 0; j < len; j++)
            (*copy)[i + 1][j + 1] = map[i][j];
        (*copy)[i + 1][len + 1] = 'X';
        (*copy)[i + 1][len + 2] = '\0';
    }
    for (int i = 0; i < len + 2; i++)
        (*copy)[tab_len + 1][i] = 'X';
    (map[tab_len - 1][len - 1] == '*') ? ((*copy)[tab_len][len] = 'F') :
    (printf("no solution found"), exit(0));
}

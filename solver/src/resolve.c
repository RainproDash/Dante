/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-vivien.boitard
** File description:
** resolve
*/

#include "header.h"
#include <stdio.h>
#include <stdbool.h>

static void print_map(char **map)
{
    int i = 0;

    for (; map[i + 1] != NULL; i++)
        printf("%s\n", map[i]);
    for (int j = 0; map[i][j + 1] != '\0'; j++)
        printf("%c", map[i][j]);
    printf("%c", 'o');
}

static void change_map(char **map, char **copy)
{
    for (int i = 0; copy[i] != NULL; i++)
        for (int j = 0; copy[i][j] != '\0'; j++)
            (copy[i][j] == 'o') ? (map[i - 1][j - 1] = 'o') : (0);
}

static bool solve_maze(int y, int x, char **map)
{
    if (map[y][x] == 'F')
        return true;
    if (map[y][x] != '*')
        return false;
    map[y][x] = 'o';
    if (solve_maze(y + 1, x, map) == true)
        return true;
    if (solve_maze(y, x + 1, map) == true)
        return true;
    if (solve_maze(y - 1, x, map) == true)
        return true;
    if (solve_maze(y, x - 1, map) == true)
        return true;
    map[y][x] = 'b';
    return false;
}

void resolve(char **map, char **copy)
{
    int x = 1;
    int y = 1;

    if (solve_maze(y, x, copy) == false) {
        printf("no solution found");
        return;
    }
    change_map(map, copy);
    print_map(map);
}

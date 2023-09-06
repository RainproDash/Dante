/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main
*/

#include "header.h"
#include <time.h>

void random_star(char **map, int i, int j)
{
    int n = rand() % 2;

    if (n == 0)
        map[i - 1][j] = '*';
    else
        map[i][j - 1] = '*';
}

void put_star(char **map, int i, int j)
{
    if (i == 0 || j == 0)
        map[i][j] = '*';
    else {
        if (i % 2 == 0 && j % 2 == 0) {
            map[i][j] = '*';
            random_star(map, i, j);
        } else
            map[i][j] = 'X';
    }
}

static void free_tab(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

void generate_maze(int x, int y, int perfect)
{
    char **map = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        map[i][x] = '\0';
    }
    map[y] = NULL;
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            put_star(map, i, j);
    map[y - 1][x - 1] = '*';
    if (map[y - 1][x - 2] == 'X' && map[y - 2][x - 1] == 'X')
        map[y - 2][x - 1] = '*';
    if (perfect == 1)
        for (int i = 0; i < x - 1; i++)
            map[y - 1][i] = '*';
    for (int i = 0; i < y - 1; i++)
        printf("%s\n", map[i]);
    printf("%s", map[y - 1]);
    free_tab(map);
}

int main(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return 84;
    if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0)
        return 84;
    if (ac == 4 && strcmp(av[3], "perfect") != 0)
        return 84;
    srand(time(NULL));
    if (atoi(av[1]) == 2 && atoi(av[2]) == 2) {
        printf("*X\n**");
        return 0;
    }
    if (ac == 3)
        generate_maze(atoi(av[1]), atoi(av[2]), 1);
    else
        generate_maze(atoi(av[1]), atoi(av[2]), 0);
    return 0;
}

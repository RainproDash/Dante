/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-vivien.boitard
** File description:
** destroy
*/

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void destroy_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

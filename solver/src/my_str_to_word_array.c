/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday08-vivien.boitard
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <string.h>

static int nb_line(char *str, char *delim)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == delim[0])
            n++;
    return (n);
}

void my_str_to_word_array(char *str, char ***tab, char *delim)
{
    char *copy = strdup(str);
    char *ptr = strtok(copy, delim);
    int n = nb_line(str, delim) + 1;

    *tab = malloc(sizeof(char *) * (n + 1));
    for (int i = 0; i < n && ptr != NULL; i++) {
        (*tab)[i] = malloc(sizeof(char) * (strlen(ptr) + 1));
        strcpy((*tab)[i], ptr);
        ptr = strtok(NULL, delim);
    }
    (*tab)[n] = NULL;
    free(copy);
}

/*
** EPITECH PROJECT, 2023
** dante
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_

void error_management(int ac, char **av);

void check_file(char **map);

void my_str_to_word_array(char *str, char ***tab, char *delim);

void creat_copy(char ***copy, char **map);

void resolve(char **map, char **copy);

void destroy_tab(char **tab);

#endif /* !HEADER_H_ */

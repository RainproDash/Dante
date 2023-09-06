/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main
*/

#include "header.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void open_file(char ***buffer, char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    int size;
    char *buf;

    stat(path, &st);
    size = st.st_size;
    buf = malloc(sizeof(char *) * size);
    read(fd, buf, size);
    buf[size] = '\0';
    my_str_to_word_array(buf, &(*buffer), "\n");
    free(buf);
    close(fd);
}

int main(int ac, char **av)
{
    int fd;
    char **buffer = NULL;
    char **copy = NULL;

    error_management(ac, av);
    open_file(&buffer, av[1]);
    check_file(buffer);
    creat_copy(&copy, buffer);
    resolve(buffer, copy);
    destroy_tab(buffer);
    return 0;
}

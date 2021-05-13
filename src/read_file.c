/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** read_file
*/

#include "../include/sokoban.h"

int read_file(int ac, char **av)
{
    char *buff;
    int size;
    struct stat sb;

    buff = malloc(5000);
    size = read(open(av[1], O_RDONLY), buff, 5000);
    if (size == 0 || size == -1)
        return (84);
    buff[size] = 0;
    check_player(buff);
    check_nb_boxhole(buff);
    check_char(buff);
    sokoban_disp(my_str_to_word_array(buff), buff);
    free(buff);
    return (0);
}
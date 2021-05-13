/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** main
*/

#include "include/sokoban.h"

void term_size(char *path, char **tab)
{
    while (LINES < my_arrlen(tab) || COLS < my_linelen(path)) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 11, "Terminal too small.");
        refresh();
    }
}

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, containing '#'");
    my_putstr("for walls, \n\t'P' for the player, 'X' for boxes and 'O'");
    my_putstr("for storage locations\n");
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (my_strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    if (read_file(ac, av) == 0)
        return (0);
    else
        return (84);
    return (0);
}
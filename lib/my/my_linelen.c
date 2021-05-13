/*
** EPITECH PROJECT, 2021
** my_linelen.c
** File description:
** my_linelen.c
*/

#include "../../include/sokoban.h"

int my_linelen(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i += 1;
    return (i);
}

int my_nbline(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != 0) {
        if (str[i] == '\n')
            nb += 1;
        i += 1;
    }
    return (nb);
}
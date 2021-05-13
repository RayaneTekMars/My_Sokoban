/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "../../include/sokoban.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i += 1;
    return (i);
}
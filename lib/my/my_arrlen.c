/*
** EPITECH PROJECT, 2021
** my_arrlen.c
** File description:
** my_arrlen.c
*/

#include "../../include/sokoban.h"

int my_arrlen(char **arr)
{
    int i = 0;

    while (arr[i] != NULL)
        i += 1;
    return (i);
}
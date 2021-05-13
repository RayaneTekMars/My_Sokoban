/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** error
*/

#include "../include/sokoban.h"

void check_player(char *path)
{
    int i = 0;
    int player = 0;

    while (path[i] != '\0') {
        if (path[i] == 'P')
            player++;
        i++;
    }
    if (player > 1)
        exit(84);
}

void check_nb_boxhole(char *path)
{
    int boxes = 0;
    int holes = 0;
    int i = 0;

    while (path[i] != '\0') {
        if (path[i] == 'O')
            holes++;
        if (path[i] == 'X')
            boxes++;
        i++;
    }
    if (boxes != holes)
        exit(84);
}

void check_char(char *path)
{
    int i = 0;

    while (path[i] != '\0') {
        if (path[i] != '#' && path[i] != ' ' &&
            path[i] != 'O' && path[i] != 'X' &&
            path[i] != 'P' && path[i] != '\n')
            exit(84);
        i++;
    }
}
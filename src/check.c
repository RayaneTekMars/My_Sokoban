/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** check
*/

#include "../include/sokoban.h"

int count_boxes(char **tab, char *path)
{
    int nb = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; j != my_linelen(path); j++) {
            if (tab[i][j] == 'X')
                nb += 1;
        }
    }
    return (nb);
}

int check_lose(char **tab, char *path)
{
    int boxes = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; j != my_linelen(path); j++) {
            if (tab[i][j] == 'X' && check_boxes(tab, i, j) == 1)
                boxes += 1;
        }
    }
    if (boxes == count_boxes(tab, path)) {
        return (1);
    }
    return (0);
}

int check_boxes(char **tab, int x, int y)
{
    if ((tab[x - 1][y] == '#' || tab[x - 1][y] == 'X')
        && (tab[x][y - 1] == '#' || tab[x][y + 1] == '#'
        || tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X'))
        return (1);
    if ((tab[x + 1][y] == '#' || tab[x + 1][y] == 'X')
        && (tab[x][y - 1] == '#' || tab[x][y + 1] == '#'
        || tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X'))
        return (1);
    return (0);
}

int check_spot(char **tab, t_coords *hole_pos)
{
    int i = 0;

    for (int k = 0; hole_pos[k].x < (2000); k++) {
        if (tab[hole_pos[k].x][hole_pos[k].y] == ' ')
            tab[hole_pos[k].x][hole_pos[k].y] = 'O';
        if (tab[hole_pos[k].x][hole_pos[k].y] == 'O')
            i = 1;
        if (tab[hole_pos[k].x][hole_pos[k].y] == 'P')
            i = 1;
    }
    if (i == 1)
        return (1);
    return (0);
}
/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** positions
*/

#include "../include/sokoban.h"

t_coords coo_f(int x, int y)
{
    t_coords coo;

    coo.x = x;
    coo.y = y;
    return (coo);
}

t_coords get_pos(char **tab)
{
    t_coords coo;

    for (int i = 0 ;tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            if (tab[i][j] == 'P')
                coo = coo_f(i, j);
        }
    }
    return (coo);
}

int holes_nb(char **tab)
{
    int holes = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            if (tab[i][j] == 'O')
                holes = holes + 1;
        }
    }
    return (holes);
}

t_coords *add_pos(t_coords *hole_pos, char **tab)
{
    int k = 0;

    if ((hole_pos = malloc(sizeof(t_coords) * holes_nb(tab) + 1)) == NULL)
        return (NULL);
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            if (tab[i][j] == 'O') {
                hole_pos[k] = coo_f(i, j);
                k += 1;
            }
        }
    }
    hole_pos[k] = coo_f(2000, 2000);
    return (hole_pos);
}
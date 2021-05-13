/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** move
*/

#include "../include/sokoban.h"

t_coords check_move(char **tab, t_coords coo, char *path)
{
    int input;

    keypad(stdscr, TRUE);
    input = getch();
    switch (input) {
        case KEY_UP : coo = move_up(tab, coo);
            break;
        case KEY_DOWN : coo = move_down(tab, coo);
            break;
        case KEY_LEFT : coo = move_left(tab, coo);
            break;
        case KEY_RIGHT : coo = move_right(tab, coo);
            break;
        case 32 : sokoban_disp(my_str_to_word_array(path), path);
            break;
    }
    return (coo);
}

t_coords move_right(char **tab, t_coords coo)
{
    if (tab[coo.x][coo.y + 1] != '#' && tab[coo.x][coo.y + 1] != 'X'
    && tab[coo.x][coo.y] == 'P') {
            tab[coo.x][coo.y] = ' ';
            tab[coo.x][coo.y + 1] = 'P';
            coo = get_pos(tab);
    }
    else if (tab[coo.x][coo.y + 1] == 'X' && tab[coo.x][coo.y + 2] != '#'
    && tab[coo.x][coo.y + 2] != 'X' && tab[coo.x][coo.y] == 'P') {
            tab[coo.x][coo.y] = ' ';
            tab[coo.x][coo.y + 1] = 'P';
            tab[coo.x][coo.y + 2] = 'X';
            coo = get_pos(tab);
    }
    return (coo);
}

t_coords move_left(char **tab, t_coords coo)
{
    if (tab[coo.x][coo.y - 1] != '#' && tab[coo.x][coo.y - 1] != 'X'
    && tab[coo.x][coo.y] == 'P') {
            tab[coo.x][coo.y] = ' ';
            tab[coo.x][coo.y - 1] = 'P';
            coo = get_pos(tab);
    }
    else if (tab[coo.x][coo.y - 1] == 'X' && tab[coo.x][coo.y - 2] != '#'
    && tab[coo.x][coo.y - 2] != 'X' && tab[coo.x][coo.y] == 'P') {
            tab[coo.x][coo.y] = ' ';
            tab[coo.x][coo.y - 1] = 'P';
            tab[coo.x][coo.y - 2] = 'X';
            coo = get_pos(tab);
    }
    return (coo);
}

t_coords move_up(char **tab, t_coords coo)
{
    if (tab[coo.x - 1][coo.y] != '#' && tab[coo.x - 1][coo.y] != 'X'
    && tab[coo.x][coo.y] == 'P') {
            tab[coo.x][coo.y] = ' ';
            tab[coo.x - 1][coo.y] = 'P';
            coo = get_pos(tab);
    }
    else if (tab[coo.x - 1][coo.y] == 'X' && tab[coo.x - 2][coo.y] != '#'
    && tab[coo.x - 2][coo.y] != 'X' && tab[coo.x][coo.y] == 'P') {
            tab[coo.x][coo.y] = ' ';
            tab[coo.x - 1][coo.y] = 'P';
            tab[coo.x - 2][coo.y] = 'X';
            coo = get_pos(tab);
    }
    return (coo);
}

t_coords move_down(char **tab, t_coords coo)
{
    if (tab[coo.x + 1][coo.y] != '#' && tab[coo.x + 1][coo.y] != 'X'
    && tab[coo.x][coo.y] == 'P') {
            tab[coo.x][coo.y] = ' ';
            tab[coo.x + 1][coo.y] = 'P';
            coo = get_pos(tab);
    }
    else if (tab[coo.x + 1][coo.y] == 'X' && tab[coo.x + 2][coo.y] != '#'
    && tab[coo.x + 2][coo.y] != 'X' && tab[coo.x][coo.y] == 'P') {
            tab[coo.x][coo.y] = ' ';
            tab[coo.x + 1][coo.y] = 'P';
            tab[coo.x + 2][coo.y] = 'X';
            coo = get_pos(tab);
    }
    return (coo);
}

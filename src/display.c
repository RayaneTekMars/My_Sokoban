/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** display
*/

#include "../include/sokoban.h"

void win(void)
{
    endwin();
    exit(0);
}

void lose(void)
{
    endwin();
    exit(1);
}

int sokoban_disp(char **tab, char *path)
{
    WINDOW *box;
    t_coords coo;
    t_coords *hole_pos;

    hole_pos = add_pos(hole_pos, tab);
    coo = get_pos(tab);
    initscr();
    while (1) {
        curs_set(0);
        term_size(path, tab);
        if (check_spot(tab, hole_pos) == 0)
            win();
        if (check_lose(tab, path) == 1)
            lose();
        coo = sokoban_loop(tab, path, coo);
    }
    free(box);
    return (0);
}

t_coords sokoban_loop(char **tab, char *path, t_coords coo)
{
    int i = 0;

    clear();
    while (tab[i] != NULL) {
        mvprintw(LINES / 2 - my_arrlen(tab) / 2 + i,
        COLS / 2 - my_strlen(tab[i]) / 2, tab[i]);
        curs_set(0);
        i += 1;
    }
    refresh();
    coo = check_move(tab, coo, path);
    return (coo);
}
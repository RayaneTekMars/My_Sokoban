/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <termios.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct coords_s
{
    int x;
    int y;
} t_coords;

int my_arrlen(char **arr);
int my_linelen(char *str);
int my_nbline(char *str);
void my_putstr(char *str);
char **my_str_to_word_array(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char *str);

int read_file(int ac, char **av);
int count_boxes(char **tab, char *path);
int check_boxes(char **tab, int x, int y);
int sokoban_disp(char **tab, char *path);
int check_spot(char **tab, t_coords *hole_pos);
int nb_holes(char **tab);
int check_lose(char **tab, char *path);
t_coords sokoban_loop(char **tab, char *path, t_coords coo);
t_coords move_up(char **tab, t_coords coo);
t_coords move_down(char **tab, t_coords coo);
t_coords move_left(char **tab, t_coords coo);
t_coords move_right(char **tab, t_coords coo);
t_coords check_move(char **tab, t_coords coo, char *path);
t_coords *add_pos(t_coords *hole_pos, char **tab);
t_coords get_pos(char **tab);
t_coords coo_f(int x, int y);
void check_char(char *path);
void check_player(char *path);
void check_nb_boxhole(char *path);
void term_size(char *path, char **tab);

#endif /* !SOKOBAN_H_ */

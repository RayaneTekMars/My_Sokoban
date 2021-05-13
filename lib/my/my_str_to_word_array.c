/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "../../include/sokoban.h"

char **my_str_to_word_array(char *str)
{
    int i = 0;
    char **tab;

    if ((tab = malloc(sizeof(char *) * my_nbline(str) + 1)) == NULL)
        exit(84);
    tab[my_nbline(str)] = NULL;
    for (int k = 0; str[i] != 0; k++) {
        if ((tab[k] = malloc(sizeof(char *) * my_linelen(str) + 1)) == NULL)
            exit(84);
        for (int j = 0; str[i] != '\n' && tab[k] != NULL; j++) {
            tab[k][j] = str[i];
            i += 1;
        }
        i += 1;
    }
    return (tab);
}

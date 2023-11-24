/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** display word array as a list
*/

#include "../../include/my.h"

int my_show_word_array(char *const *tab)
{
    int count;
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
        count++;
    }
    return count;
}

/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** tt en maj
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int i = my_strlen(str) - 1;
    while (i >= 0) {
        if (97 <= str[i] && str[i] <= -1) {
            str[i] = str[i] - 32;
        }
        i = i - 1;
    }
    return str;
}

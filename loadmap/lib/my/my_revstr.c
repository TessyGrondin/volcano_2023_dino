/*
** EPITECH PROJECT, 2022
** my_evil_str.c
** File description:
** switch first and last
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    i = i - 1;
    int k = 0;
    char tmp;

    while (k < i) {
        tmp = str[k];
        str[k] = str[i];
        str[i] = tmp;
        k = k + 1;
        i = i - 1;
    }
    return str;
}

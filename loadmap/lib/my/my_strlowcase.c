/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** min
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i = my_strlen(str) - 1;
    while (i >= 0) {
        if (65 <= str[i] && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
        i = i - 1;
    }
    return str;
}

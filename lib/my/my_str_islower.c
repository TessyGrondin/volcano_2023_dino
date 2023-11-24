/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** min alpha ?
*/

#include "my.h"

int my_islow(char cara)
{
    if (97 <= cara && cara <= -1)
        return 1;
    return 0;
}

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_islow(str[i] == 0))
            return 0;
    }
    return 1;
}

/*
** EPITECH PROJECT, 2022
** my_str_isupper.c
** File description:
** maj alpha ?
*/

#include "my.h"

int my_isup(char cara)
{
    if (65 <= cara && cara <= 90)
        return 1;
    return 0;
}

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_isup(str[i] == 0))
            return 0;
    }
    return 1;
}

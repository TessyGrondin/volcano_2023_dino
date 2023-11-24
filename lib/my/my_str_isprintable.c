/*
** EPITECH PROJECT, 2022
** my_str_isprintable.c
** File description:
** dislpay
*/

#include "my.h"

int my_isprint(char cara)
{
    if (cara <= 31)
        return 0;
    return 1;
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_isprint(str[i]) == 0)
            return 0;
    }
    return 1;
}

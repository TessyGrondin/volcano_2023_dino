/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** .
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int minus = 0;
    int nb = 0;
    while (str[i] == '-' || str[i] == '+' || my_isnum(str[i])) {
        if (my_isnum(str[i]))
            nb = nb * 10 + str[i] - 48;
        if (str[i] == '-')
            minus = minus + 1;
        if (my_isnum(str[i]) == 1 && my_isnum(str[i + 1] == 0))
            break;
        i = i + 1;
    }
    if (minus % 2 == 1)
        nb = -nb;
    return nb;
}

/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** num ?
*/

#include <stddef.h>
#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 1;
    while (str[i] != '\0') {
        if (my_isnum(str[i]) == 0)
            return 0;
        i = i + 1;
    }
    return 1;
}

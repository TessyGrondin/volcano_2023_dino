/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** alha ?
*/

#include <stddef.h>
#include "my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 1;
    while (str[i] != '\0') {
        if (my_isalpha(str[i]) == 0)
            return 0;
        i = i + 1;
    }
    return 1;
}

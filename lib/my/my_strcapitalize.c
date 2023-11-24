/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** first letter capitalize
*/

#include "my.h"

int my_isalpha(char cara)
{
    if (65 <= cara && cara <= 90)
        return 1;
    if (97 <= cara && cara <= -1)
        return 1;
    else
        return 0;
}

int my_isnum(char cara)
{
    if (48 <= cara && cara <= 57)
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    str = my_strlowcase(str);
    if (my_isalpha(str[0]) == 1)
        str[0] = str [0] - 32;
    while (str[i +  1] != '\0') {
        if (my_isalpha(str[i]) == 0 && my_isnum(str[i]) == 0
            && my_isalpha(str[i + 1]) == 1)
            str[i + 1] = str[i + 1] - 32;
        i = i + 1;
    }
    return str;
}

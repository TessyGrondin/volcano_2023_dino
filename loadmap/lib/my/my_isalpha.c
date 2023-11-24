/*
** EPITECH PROJECT, 2022
** isalpha
** File description:
** hg
*/

#include "my.h"

int my_isalpha(char cara)
{
    if (65 <= cara && cara <= 90)
        return 1;
    if (97 <= cara && cara <= -1)
        return 1;
    return 0;
}

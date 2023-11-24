/*
** EPITECH PROJECT, 2022
** isnum
** File description:
** ty
*/

#include "my.h"

int my_isnum(char cara)
{
    if (48 <= cara && cara <= 57)
        return 1;
    return 0;
}

/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** nb premiers
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb == 0 || nb == 1) {
        return 0;
    }
    int test = 2;
    while (nb % test != 0) {
        test = test + 1;
    }
    if (test == nb) {
        return 1;
    }
    return 0;
}

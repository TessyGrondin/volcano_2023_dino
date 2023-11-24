/*
** EPITECH PROJECT, 2022
** my_find_prime_sup.c
** File description:
** prime sup ?
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1) {
        return nb;
    }
    return my_find_prime_sup(nb + 1);
}

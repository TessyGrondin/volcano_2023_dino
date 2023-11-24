/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** square roots
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 1;
    if (nb <= 0) {
        return 0;
    }
    while (i * i <= nb) {
        if (i * i == nb) {
            return i;
        }
        i = i + 1;
    }
    return 0;
}

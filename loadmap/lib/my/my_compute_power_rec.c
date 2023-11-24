/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** nb à la puissance p rec
*/
#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p <= 0) {
        return 1;
    }
    if (p == 1) {
        return nb;
    }
    int res = nb * my_compute_power_rec(nb, p - 1);
    return res;
}

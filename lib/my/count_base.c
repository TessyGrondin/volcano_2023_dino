/*
** EPITECH PROJECT, 2022
** count base
** File description:
** because I don't wanna display
*/

#include "../../include/my.h"

int my_count_base(int nb, char const *base)
{
    int i = 0;
    int e = my_strlen(base);

    while ((nb / e) > my_strlen(base) - 1)
        e *= my_strlen(base);
    while (e >= 1) {
        nb %= e;
        e /= my_strlen(base);
        i++;
    }
    return i;
}

int my_count_float(double nbr, int acc)
{
    int e = my_compute_power_rec(10, acc);
    int a = nbr;
    int b = (nbr * e) - (a * e);
    int c = 0;
    c = my_nblen(a) + my_nblen(b) + 1;
    return c;
}

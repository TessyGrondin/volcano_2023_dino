/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** convert and display
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putnbr_base(int nbr, char const *base)
{
    int E = my_strlen(base);
    int tmp;
    int count = 0;

    if (nbr < 0) {
        nbr = nbr * -1;
        write(1, "-", 1);
    }
    while (nbr / E > my_strlen(base) - 1)
        E = E * my_strlen(base);
    while (E >= 1) {
        tmp = nbr / E;
        write(1, &base[tmp], 1);
        nbr = nbr % E;
        E = E / my_strlen(base);
        count++;
    }
    return count;
}

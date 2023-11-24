/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** afficher nombres
*/

#include <unistd.h>
#include "my.h"
#include <stdlib.h>

int my_put_nbr(int nb)
{
    int E = 10;
    int tmp;
    if (nb < 0) {
        nb = nb * (-1);
        write(1, "-", 1);
    }
    while (nb / E > 9) {
        E = E * 10;
    }
    while (E >= 1) {
        tmp = nb / E +48;
        write(1, &tmp, 1);
        nb = nb % E;
        E = E / 10;
    }
    return 0;
}

char *get_str_from_nbr(int nb)
{
    int E = 10;
    char tmp;
    char *result = malloc(sizeof(char) * 11);
    int i = 0;
    if (nb < 0) {
        nb = nb * (-1);
        result[0] = '-';
        i++;
    }
    while (nb / E > 9) {
        E = E * 10;
    }
    for (; E >= 1 && i < 11; i++) {
        tmp = nb / E +48;
        result[i] = tmp;
        nb = nb % E;
        E = E / 10;
    }
    result[i] = '\0';
    return result;
}

/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** negative or not
*/

#include <unistd.h>
#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        write(1, "N", 1);
    }

    if (n >= 0) {
        write(1, "P", 1);
    }
    return 0;
}

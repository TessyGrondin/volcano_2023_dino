/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** display
*/

#include <unistd.h>
#include "my.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}

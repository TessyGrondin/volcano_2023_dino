/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** display string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        char lien = str[i];
        write(1, &lien, 1);
        i = i + 1;
    }
    return 0;
}

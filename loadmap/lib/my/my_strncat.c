/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** i = "dest" +"src"
*/

#include <stdlib.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i = my_strlen(dest);
    int j = 0;

    while (j != n) {
        dest[i + j] = src[j];
        j = j + 1;
    }
    return dest;
}

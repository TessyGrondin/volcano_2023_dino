/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** renvoie une copie
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    for (; src[i] && i < n; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}

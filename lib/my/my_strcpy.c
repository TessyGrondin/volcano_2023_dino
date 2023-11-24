/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** renvoie une copie
*/
#include <string.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

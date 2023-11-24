/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** swap int values
*/
#include "my.h"

void my_swap(int *a, int *b)
{
    int c = *a;
    int d = *b;
    *a = d;
    *b = c;
}

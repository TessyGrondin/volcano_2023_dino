/*
** EPITECH PROJECT, 2022
** strncmp
** File description:
** strncmp
*/
#include <unistd.h>
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int k = 0;

    while (i != n)
        i++;
    while (s1[k] == s2[k] && k != n)
        k++;
    if (k == i)
        return 0;
    if (s1[k] < s2[k]) {
        return -1;
    } else {
        return 1;
    }
}

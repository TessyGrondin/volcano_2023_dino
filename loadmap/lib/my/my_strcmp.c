/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** comparaison
*/
#include <unistd.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int k = 0;

    while (s1[i] != '\0')
        i = i + 1;
    while (s1[k] == s2[k] && s1[k] != '\0')
        k = k + 1;
    if (k == i) {
        return 0;
    }
    if (s1[k] < s2[k]) {
        return -1;
    } else {
        return 1;
    }
}

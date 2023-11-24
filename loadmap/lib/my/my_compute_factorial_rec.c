/*
** EPITECH PROJECT, 2022
** my_compute_factorial_rec.c
** File description:
** recursive factorial
*/

int my_compute_factorial_rec(int nb)
{
    int res;
    if (nb < 0) {
        return 0;
    }
    if (nb == 0) {
        return 1;
    }
    if (nb >= 12) {
        return 0;
    }
    res = nb * my_compute_factorial_rec(nb - 1);
    return res;
}

/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** contain all lib/my/
*/

#pragma once
    #include <stdarg.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #define IS_PRINTABLE(c)((((c) < (32)) || ((c) > (126))) ? (0) : (1))
    #define CC(x) ((const char **)x)

typedef int (*fc)(char const *str, va_list *ap, int size);
typedef int (*ts)(char **file, int position);
char *concat_params(int size, char **src);
char *get_str_from_nbr(int nb);
int my_compute_facorial_rec(int nb);
char *my_unappend(char *str);
int my_putnbr(int nb);
void can_free(char *str);
char **tab_append(char **src, char *add);
int my_count_base(int nb, char const *base);
int my_count_float(double nbr, int acc);
int iflag(char const *str, va_list *ap, int size);
int cflag(char const *str, va_list *ap, int size);
int sflag(char const *str, va_list *ap, int size);
int fflag(char const *str, va_list *ap, int size);
int xflag(char const *str, va_list *ap, int size);
int bflag(char const *str, va_list *ap, int size);
int upsflag(char const *str, va_list *ap, int size);
int len_detector(char const *str);
int my_putnbr_base(int nbr, char const *base);
void freer(char **tab);
int my_showmem(char const *str, int size);
int stepper(char const *str);
int stepper_condition(char c);
int flagdot(char const *str, va_list *ap);
int my_putargs(char const *str, va_list *ap, int size);
int my_printf(const char *format, ...);
int my_nblen(int nb);
int my_tablen(const char **src);
int my_put_float(double nbr, int acc);
char *my_append(char *str, char c);
int my_showstr(char const *str);
int my_show_word_array(char *const *tab);
int my_str_isprintable(char const *str);
char **my_str_to_word_array(char const *str, char const *delim);
int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb,int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *des, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dset, char const *src, int n);
int my_isalpha(char cara);
int my_isnum(char cara);
char *my_strdup(char const *str);

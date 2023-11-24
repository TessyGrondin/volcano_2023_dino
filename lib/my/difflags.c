/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-florian.dajon
** File description:
** difflags
*/
#include "../../include/my.h"
#include <stdarg.h>

int iflag(char const *str, va_list *ap, int size)
{
    int i = va_arg(*ap, int);
    int j = my_nblen(i);
    int l = 0;
    (void) str;
    for (int k = 0; k < (size - j); k++)
        l += my_putchar(' ');
    return my_putnbr(i) + l;
}

int cflag(char const *str, va_list *ap, int size)
{
    int i = va_arg(*ap, int);
    int j = 0;
    (void) str;
    for (int k = 0; k < (size - 1); k++)
        j += my_putchar(' ');
    return my_putchar(i) + j;
}

int sflag(char const *str, va_list *ap, int size)
{
    char *i = va_arg(*ap, char *);
    int j = my_strlen(i);
    int k = 0;
    (void) str;
    for (int l = 0; l < (size - j); l++)
        k += my_putchar(' ');
    return my_putstr(i) + k;
}

int upsflag(char const *str, va_list *ap, int size)
{
    char *rts = va_arg(*ap, char *);
    int j = my_strlen(rts);
    int l = 0;
    int tg = my_strlen(rts);
    (void) str;
    for (int k = 0; k < (size - j); k++)
        l += my_putchar(' ');
    for (int i = 0; i < tg; i++) {
        if (IS_PRINTABLE(rts[i]) == 0) {
            l += my_putchar('\\');
            l += my_putnbr_base((unsigned char) rts[i], "01234567");
        } else
            l += my_putchar(rts[i]);
    }
    return l;
}

int bflag(char const *str, va_list *ap, int size)
{
    int i = va_arg(*ap, int);
    int j = my_count_base(i, "01");
    int k = 0;
    (void) str;
    for (int l = 0; l < (size - j); l++)
        k += my_putchar(' ');
    return my_putnbr_base(i, "01") + k;
}

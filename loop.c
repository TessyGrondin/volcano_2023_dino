/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** loop
*/

#include "include/testmap.h"

char *get_str_from_nbr(int nb)
{
    int E = 10;
    char *result = NULL;
    int i = 0;
    if (nb < 0) {
        nb = nb * (-1);
        result = my_append(result,'-');
        i++;
    }
    while (nb / E > 9) {
        E = E * 10;
    }
    for (; E >= 1 && i < 11; i++) {
        result = my_append(result, (nb / E + 48)) ;
        nb = nb % E;
        E = E / 10;
    }
    result[i] = '\0';
    return result;
}

char *concat_all(char *level, char *def, char *att)
{
    char *first = my_strdup("Level : ");
    char *sec = my_strdup("\natt. = ");
    char *third = my_strdup("\ndef. = ");
    char *res = my_strcat(first, level);
    res = my_strcat(res, my_strcat(sec, att));
    res = my_strcat(res, my_strcat(third, def));
    return res;
}

void game_loop(all_t *all)
{
    if (!all->e_menu)
        return;
    sfMusic_stop(all->sounds.menu_mus);
    main_music_manager(&all->sounds, all->sounds.game_mus);
    read_entrances(all);
    get_all_layers(all);
    sfRenderWindow_clear(all->win, sfBlack);
    if (all->is_end != 1) {
        catch_input(all);
    }
    action_player(all);
    auto_animation(all);
    alea(all);
    map_draw(all);
    sfRenderWindow_display(all->win);
}

sfSound *create_sound(char *path)
{
    sfSound *res = sfSound_create();
    sfSoundBuffer *tmp = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(res, tmp);
    return res;
}

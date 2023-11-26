/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** menu
*/

#include "include/testmap.h"

button_t get_button(sfClock *clock)
{
    button_t res;
    res.look = sp_create(P_NEW_GAME, clock, 571, 227);
    res.state = 0;
    sfSprite_setTextureRect(res.look.sp, (sfIntRect){0, 0, 571, 227});
    sfSprite_setScale(res.look.sp, (sfVector2f){0.9, 1.2});
    return res;
}

menu_t get_menu(sfClock *clock)
{
    menu_t res;
    res.bg = sp_create(P_MM_BG, clock, 1920, 1080);
    res.start = get_button(clock);
    sfSprite_setTextureRect(res.bg.sp, (sfIntRect){0, 0, 1920, 1080});
    sfSprite_setScale(res.bg.sp, (sfVector2f){0.9, 1.2});
    return res;
}

void display_menu(all_t *all)
{
    if (button_click(all) == 0) {
        sfMusic_stop(all->sounds.loose_mus);
        sfMusic_stop(all->sounds.win_mus);
        sfMusic_stop(all->sounds.game_mus);
        main_music_manager(&all->sounds, all->sounds.menu_mus);
        button_highlight(all);
        sfRenderWindow_drawSprite(all->win, all->menu.bg.sp, NULL);
        display_button(&all->menu.start, all, (sfVector2f){590, 955});
    } else
        all->states = GAME;
}

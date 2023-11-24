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
    res.look = sp_create(P_NEW_GAME, clock);
    res.state = 0;
    sfSprite_setTextureRect(res.look.sp, (sfIntRect){128, 0, 64, 24});
    return res;
}

menu_t get_menu(sfClock *clock)
{
    menu_t res;
    res.bg = sp_create(P_MM_BG, clock);
    res.start = get_button(clock);
    sfSprite_setTextureRect(res.bg.sp, (sfIntRect){0, 0, 1280, 720});
    sfSprite_setScale(res.bg.sp, (sfVector2f){0.4, 0.4});
    return res;
}

void display_menu(all_t *all)
{
    if (all->e_menu == 1)
        return;
    if (button_click(all) == 0) {
        sfMusic_stop(all->sounds.loose_mus);
        sfMusic_stop(all->sounds.win_mus);
        sfMusic_stop(all->sounds.game_mus);
        main_music_manager(&all->sounds, all->sounds.menu_mus);
        sfRenderWindow_clear(all->win, sfBlack);
        button_highlight(all);
        sfRenderWindow_drawSprite(all->win, all->menu.bg.sp, NULL);
        display_button(&all->menu.start, all, (sfVector2f){350, 100});
        sfRenderWindow_display(all->win);
    }
}


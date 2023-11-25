/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** endgame
*/

#include "include/testmap.h"

sfBool display_loose(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    if (timing - all->move <= 10) {
        sfSprite_setScale(all->end.sp, (sfVector2f){0.25, 0.3});
        sfSprite_setTextureRect(all->end.sp, (sfIntRect){0, 0, 1920, 1080});
        sfRenderWindow_drawSprite(all->win, all->end.sp, NULL);
        return sfTrue;
    } else
        all->states = GAME;
    return sfFalse;
}

void loose(all_t *all)
{
    sfMusic_stop(all->sounds.game_mus);
    main_music_manager(&all->sounds, all->sounds.loose_mus);
    if (!display_loose(all)) {
        all->player.offering = 0;
        sfSprite_setPosition(all->player.sp.sp, (sfVector2f){240, 128});
        change_map(all, 4);
    }
}

sfBool display_win(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    if (timing - all->move <= 15) {
        sfSprite_setScale(all->end.sp, (sfVector2f){0.25, 0.3});
        sfSprite_setTextureRect(all->end.sp, (sfIntRect){1920, 0, 1920, 1080});
        sfRenderWindow_drawSprite(all->win, all->end.sp, NULL);
        return sfTrue;
    } else
        all->states = MENU;
    return sfFalse;
}

void win(all_t *all)
{
    // if (all->current_map == 8) {
        sfMusic_stop(all->sounds.game_mus);
        main_music_manager(&all->sounds, all->sounds.win_mus);
        if (!display_win(all)) {
            // init_state(&all->player);
            sfSprite_setPosition(all->player.sp.sp, (sfVector2f){240, 128});
            change_map(all, 4);
            all->states = MENU;
            all->menu.start.state = 0;
        }
    // }
}

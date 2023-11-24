/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** endgame
*/

#include "include/testmap.h"

// void set_last_npc(all_t *all)
// {
//     sfVector2f set = {100, 250};
//     if (all->current_map == 5 && all->player.rings == 7)
//         sfSprite_setPosition(all->npc.self.sp, set);
// }

sfBool display_loose(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    if (timing - all->move <= 10) {
        sfSprite_setScale(all->end.sp, (sfVector2f){0.4, 0.4});
        sfSprite_setTextureRect(all->end.sp, (sfIntRect){0, 0, 1280, 720});
        sfRenderWindow_drawSprite(all->win, all->end.sp, NULL);
        return sfTrue;
    } else
        all->is_end = 0;
    return sfFalse;
}

void loose(all_t *all)
{
    if (all->player.hp <= 0) {
        all->is_end = 1;
        sfMusic_stop(all->sounds.game_mus);
        main_music_manager(&all->sounds, all->sounds.loose_mus);
        if (!display_loose(all)) {
            init_state(&all->player);
            sfSprite_setPosition(all->player.sp.sp, (sfVector2f){240, 128});
            change_map(all, 4);
        }
    }
}

sfBool display_win(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    if (timing - all->move <= 15) {
        sfSprite_setScale(all->end.sp, (sfVector2f){0.4, 0.4});
        sfSprite_setTextureRect(all->end.sp, (sfIntRect){1280, 0, 1280, 720});
        sfRenderWindow_drawSprite(all->win, all->end.sp, NULL);
        // play_dialogue(&all->npc, all);
        all->is_end = 1;
        return sfTrue;
    } else
        all->is_end = 0;
    return sfFalse;
}

void win(all_t *all)
{
    // if (all->current_map == 8 && all->npc.can_dialogue == 1) {
    if (all->current_map == 8) {
        sfMusic_stop(all->sounds.game_mus);
        main_music_manager(&all->sounds, all->sounds.win_mus);
        if (!display_win(all)) {
            init_state(&all->player);
            sfSprite_setPosition(all->player.sp.sp, (sfVector2f){240, 128});
            change_map(all, 4);
            all->e_menu = 0;
            all->menu.start.state = 0;
        }
    }
}

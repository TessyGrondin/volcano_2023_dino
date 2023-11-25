/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** anim
*/

#include "include/testmap.h"

void play_animation(sprite_t *entit, all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    sfIntRect rect = sfSprite_getTextureRect(entit->sp);
    anim_player(all);
    if (timing - entit->lat >= 0.15 || all->force_anim_change) {
        if (entit->frame == 3) {
            rect.left = entit->anim * 32 * 4;
            entit->frame = 0;
        } else {
            rect.left += 32;
            entit->frame++;
        }
        sfSprite_setTextureRect(entit->sp, rect);
        entit->lat = timing;
    }
}

void draw_sprite(all_t *all)
{
    for (int i = 0; all->enemies[i].sp != NULL; i++)
        sfRenderWindow_drawSprite(all->win, all->enemies[i].sp, NULL);
    sfRenderWindow_drawSprite(all->win, all->player.sp.sp, NULL);
    for (int i = 0; all->target[i].sp.sp != NULL; i++)
        if (all->target[i].alive == 1)
            sfRenderWindow_drawSprite(all->win, all->target[i].sp.sp, NULL);
}

void anim_everyone(all_t *all)
{
    for (int i = 0; all->enemies[i].sp != NULL; i++)
        play_animation(&all->enemies[i], all);
    for (int i = 0; all->enemies[i].sp != NULL; i++)
        move(&all->enemies[i]);

    for (int i = 0; all->target[i].sp.sp != NULL; i++)
        anim_npc(&all->target[i], all);
    for (int i = 0; all->target[i].sp.sp != NULL; i++)
        move(&all->target[i].sp);

    monster_collisions(all);
    map_borders(all);
    all->force_anim_change = 0;
}

void auto_animation(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    if (!all->charged || all->is_end == 1) return;
    if (timing - all->move >= 2) {
        for (int i = 0; all->enemies[i].sp != NULL; i++) {
            all->enemies[i].anim = rand() % 20;
            all->enemies[i].anim = ((all->enemies[i].anim) > 9) ? 0 : all->enemies[i].anim;
            all->enemies[i].anim = ((all->enemies[i].anim) == 1) ? 0 : all->enemies[i].anim;
            all->enemies[i].frame = 3;
        }
        for (int i = 0; all->target[i].sp.sp != NULL; i++) {
            all->target[i].sp.anim = rand() % 20;
            all->target[i].sp.anim = ((all->target[i].sp.anim) > 9) ? 0 : all->target[i].sp.anim;
            all->target[i].sp.anim = ((all->target[i].sp.anim) == 1) ? 0 : all->target[i].sp.anim;
            all->target[i].sp.frame = 3;
        }
        all->move = timing;
        all->force_anim_change = 1;
    }
    anim_everyone(all);
}

/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** anim
*/

#include "include/testmap.h"

void play_animation(sprite_t *entit, all_t *all, int width)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    sfIntRect rect = sfSprite_getTextureRect(entit->sp);
    anim_player(all);
    if (timing - entit->lat >= 0.15 || all->force_anim_change) {
        if (entit->frame == 3) {
            rect.left = entit->anim * width * 4;
            entit->frame = 0;
        } else {
            rect.left += width;
            entit->frame++;
        }
        sfSprite_setTextureRect(entit->sp, rect);
        entit->lat = timing;
    }
}

void draw_sprite(all_t *all)
{
    sfRenderWindow_drawSprite(all->win, all->altar.sp.sp, NULL);
    for (int i = 0; all->enemies[i].sp != NULL; i++)
        sfRenderWindow_drawSprite(all->win, all->enemies[i].sp, NULL);
    for (int i = 0; all->target[i].sp.sp != NULL; i++)
        if (all->target[i].alive == sfTrue && all->target[i].map == all->current_map)
            sfRenderWindow_drawSprite(all->win, all->target[i].sp.sp, NULL);
    sfRenderWindow_drawSprite(all->win, all->player.sp.sp, NULL);
}

void anim_everyone(all_t *all)
{
    for (int i = 0; all->enemies[i].sp != NULL; i++)
        play_animation(&all->enemies[i], all, CROC_WIDTH);
    for (int i = 0; all->enemies[i].sp != NULL; i++)
        move(&all->enemies[i]);

    for (int i = 0; all->target[i].sp.sp != NULL; i++)
        play_animation(&all->target[i].sp, all, SP_WIDTH);
    for (int i = 0; all->target[i].sp.sp != NULL; i++) {
        move(&all->target[i].sp);
        collisions(&all->target[i].sp, all);
    }

    monster_collisions(all);
    map_borders(all);
    all->force_anim_change = 0;
}

void auto_animation(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    if (!all->charged) return;
    if (timing - all->move >= 2) {
        for (int i = 0; all->enemies[i].sp != NULL; i++) {
            all->enemies[i].anim = rand() % 4;
            all->enemies[i].frame = 3;
        }
        for (int i = 0; all->target[i].sp.sp != NULL; i++) {
            all->target[i].sp.anim = rand() % 4;
            all->target[i].sp.frame = 3;
        }
        all->move = timing;
        all->force_anim_change = 1;
    }
    anim_everyone(all);
}

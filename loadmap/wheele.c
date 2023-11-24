/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** wheel
*/

#include "include/testmap.h"

void anim_wheel(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    sfIntRect rect = sfSprite_getTextureRect(all->player.wheel.sp);
    if (all->player.use_wheel == 0)
        return;
    if (timing - all->player.wheel.lat >= 0.1 &&
    all->player.use_wheel) {
        if (all->player.wheel.frame == 12) {
            all->player.wheel.frame = 0;
            all->player.use_wheel = 0;
            rect.left = 0;
        } else {
            rect.left += 64;
            all->player.wheel.frame++;
        }
        sfSprite_setTextureRect(all->player.wheel.sp, rect);
        all->player.wheel.lat = timing;
    }
}

void draw_wheel(all_t *all)
{
    sfVector2f pos = sfSprite_getPosition(all->player.sp.sp);
    pos.x -= 10;
    pos.y -= 10;
    sfSprite_setPosition(all->player.wheel.sp, pos);
    if (sfKeyboard_isKeyPressed(sfKeyA))
        all->player.use_wheel = 1;
    if (all->player.use_wheel) {
        all->player.anim = 0;
        sfSprite_move(all->player.sp.sp, inverse_move(&all->player));
        sfRenderWindow_drawSprite(all->win, all->player.wheel.sp, NULL);
    }
}

void hit_wheel(all_t *all)
{
    if (all->player.use_wheel == 0)
        for (int i = 0; all->ent[i].sp.sp; i++)
            all->ent[i].use_wheel = 0;
    for (int i = 0; all->ent[i].sp.sp; i++) {
        if (is_colliding(&all->player.wheel, &all->ent[i].sp)) {
            check_hp(&all->ent[i], &all->player);
            all->ent[i].anim = 1;
        }
    }
}

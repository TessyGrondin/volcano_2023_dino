/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** fire
*/

#include "include/testmap.h"

void catch_fire_two(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
            all->player.use_fire = 1;
            all->player.orientation = 3;
            return;
        }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        all->player.use_fire = 1;
        all->player.orientation = 4;
        return;
    }
}

void catch_fire_one(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        all->player.use_fire = 1;
        all->player.orientation = 1;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        all->player.use_fire = 1;
        all->player.orientation = 2;
        return;
    }
    catch_fire_two(all);
}

void set_orientation(sprite_t *fire, int orientation)
{
    float ori = (orientation == 1) ? 270 : 0;
    ori = (orientation == 2) ? 180 : ori;
    ori = (orientation == 3) ? 90 : ori;
    ori = (orientation == 4) ? 0 : ori;
    sfSprite_setOrigin(fire->sp, (sfVector2f){32, 32});
    sfSprite_setRotation(fire->sp, ori);
}

void anim_fire(all_t *all, int orientation)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    sfIntRect rect = sfSprite_getTextureRect(all->player.ball.sp);
    set_orientation(&all->player.ball, orientation);
    if (timing - all->player.ball.lat >= 0.15
    && all->player.use_fire == 1) {
        if (all->player.ball.frame == 4) {
            rect.left = 0;
            all->player.ball.frame = 0;
        } else {
            rect.left += 64;
            all->player.ball.frame++;
        }
        sfSprite_setTextureRect(all->player.ball.sp, rect);
        all->player.ball.lat = timing;
    }
    // fire_move(&all->player);
}

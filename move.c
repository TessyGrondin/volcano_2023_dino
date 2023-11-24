/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** move
*/

#include "include/testmap.h"

void move_diagonal(sprite_t *sprite)
{
    sfVector2f upleft = {-1, -1};
    sfVector2f downright = {1, 1};
    sfVector2f upright = {1, -1};
    sfVector2f downleft = {-1, 1};
    if (sprite->anim == DOWNLEFT)
        sfSprite_move(sprite->sp, downleft);
    if (sprite->anim == DOWNRIGHT)
        sfSprite_move(sprite->sp, downright);
    if (sprite->anim == UPRIGHT)
        sfSprite_move(sprite->sp, upright);
    if (sprite->anim == UPLEFT)
        sfSprite_move(sprite->sp, upleft);
}

void last_input(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        all->player.sp.anim = UP;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        all->player.sp.anim = DOWN;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        find_last_move(&all->player);
        all->player.bite = sfTrue;
        use_bite(&all->player, all);
        return;
    }
    all->player.sp.anim = 0;
}

void other_input(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) &&
    sfKeyboard_isKeyPressed(sfKeyLeft)) {
        all->player.sp.anim = DOWNLEFT;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) &&
    sfKeyboard_isKeyPressed(sfKeyRight)) {
        all->player.sp.anim = DOWNRIGHT;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        all->player.sp.anim = LEFT;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        all->player.sp.anim = RIGHT;
        return;
    }
    last_input(all);
}

void catch_input(all_t *all)
{
    all->player.last = all->player.sp.anim;
    all->player.last_move = is_move(all->player.sp.anim, all->player.last_move);
    sfSprite_setScale(all->player.sp.sp, (sfVector2f){1, 1});
    sfSprite_setOrigin(all->player.sp.sp, (sfVector2f){0, 0});
    // if (all->player.use_wheel || all->npc.can_dialogue == 1)
    //     return;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        all->player.sp.anim = UPLEFT;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        all->player.sp.anim = UPRIGHT;
        return;
    }
    other_input(all);
}

void move(sprite_t *sprite)
{
    sfVector2f left = {-1, 0};
    sfVector2f right = {1, 0};
    sfVector2f up = {0, -1};
    sfVector2f down = {0, 1};
    if (sprite->anim == LEFT)
        sfSprite_move(sprite->sp, left);
    if (sprite->anim == RIGHT)
        sfSprite_move(sprite->sp, right);
    if (sprite->anim == UP)
        sfSprite_move(sprite->sp, up);
    if (sprite->anim == DOWN)
        sfSprite_move(sprite->sp, down);
    move_diagonal(sprite);
}

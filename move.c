/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** move
*/

#include "include/testmap.h"

void move(enti_t *ent)
{
    sfVector2f left = {-1, 0};
    sfVector2f right = {1, 0};
    sfVector2f up = {0, -1};
    sfVector2f down = {0, 1};
    if (ent->anim == LEFT)
        sfSprite_move(ent->sp.sp, left);
    if (ent->anim == RIGHT)
        sfSprite_move(ent->sp.sp, right);
    if (ent->anim == UP)
        sfSprite_move(ent->sp.sp, up);
    if (ent->anim == DOWN)
        sfSprite_move(ent->sp.sp, down);
    move_diagonal(ent);
}

void move_diagonal(enti_t *ent)
{
    sfVector2f upleft = {-1, -1};
    sfVector2f downright = {1, 1};
    sfVector2f upright = {1, -1};
    sfVector2f downleft = {-1, 1};
    if (ent->anim == DOWNLEFT)
        sfSprite_move(ent->sp.sp, downleft);
    if (ent->anim == DOWNRIGHT)
        sfSprite_move(ent->sp.sp, downright);
    if (ent->anim == UPRIGHT)
        sfSprite_move(ent->sp.sp, upright);
    if (ent->anim == UPLEFT)
        sfSprite_move(ent->sp.sp, upleft);
}

void catch_input(all_t *all)
{
    all->player.last = all->player.anim;
    all->player.last_move = is_move(all->player.anim, all->player.last_move);
    sfSprite_setScale(all->player.sp.sp, (sfVector2f){1, 1});
    sfSprite_setOrigin(all->player.sp.sp, (sfVector2f){0, 0});
    if (all->player.use_wheel || all->npc.can_dialogue == 1)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        all->player.anim = UPLEFT;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        all->player.anim = UPRIGHT;
        return;
    }

    other_input(all);
}

void other_input(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) &&
    sfKeyboard_isKeyPressed(sfKeyLeft)) {
        all->player.anim = DOWNLEFT;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) &&
    sfKeyboard_isKeyPressed(sfKeyRight)) {
        all->player.anim = DOWNRIGHT;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        all->player.anim = LEFT;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        all->player.anim = RIGHT;
        return;
    }
    last_input(all);
}

void last_input(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        all->player.anim = UP;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        all->player.anim = DOWN;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        find_last_move(&all->player);
        all->player.use_sword = 1;
        use_sword(&all->player, all);
        return;
    }
    all->player.anim = 0;
}

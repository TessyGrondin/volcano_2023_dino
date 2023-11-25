/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** player
*/

#include "include/testmap.h"

void anim_player(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    sfIntRect rect = sfSprite_getTextureRect(all->player.sp.sp);
    if (timing - all->player.sp.lat >= 0.15 ||
    all->player.last != all->player.sp.anim) {
        if (all->player.sp.frame == 3) {
            rect.left = all->player.sp.anim * 32 * 4;
            all->player.sp.frame = 0;
        } else {
            rect.left += 32;
            all->player.sp.frame++;
        }
        sfSprite_setTextureRect(all->player.sp.sp, rect);
        all->player.sp.lat = timing;
    }
}

// void no_more_invincible(all_t *all)
// {
//     sfTime time = sfClock_getElapsedTime(all->clock);
//     float timing = sfTime_asSeconds(time);
//     if (timing - all->player.invicibility_time >= 0.5 &&
//     all->player.invincible == 1) {
//         all->player.invincible = 0;
//         all->player.invicibility_time = timing;
//     }
// }

sprite_t sp_create(char *path, sfClock *cl)
{
    sfIntRect r = {0, 0, 32, 32};
    sprite_t res = {0};
    res.sp = sfSprite_create();
    res.tex = sfTexture_createFromFile(path, NULL);
    res.frame = 0;
    res.lat = sfTime_asSeconds(sfClock_getElapsedTime(cl));
    res.anim = 0;
    sfSprite_setTexture(res.sp, res.tex, sfFalse);
    sfSprite_setTextureRect(res.sp, r);
    return res;
}

text_box_t create_text_box()
{
    text_box_t res = {0};
    res.text = sfText_create();
    sfText_setFont(res.text, sfFont_createFromFile(P_FONT));
    sfText_setString(res.text, "hello");
    return res;
}

altar_t create_altar(char *path, sfClock *cl)
{
    altar_t res = {0};

    res.sp = sp_create(path, cl);
    res.text_box = create_text_box();
    res.offering = 0;
    return res;
}

void get_hit(all_t *all)
{
    for (int i = 0; all->enemies[i].sp; i++)
        if (is_colliding(&all->player.sp, &all->enemies[i]))// && all->player.invincible == 0) {
            loose(all);
            // all->player.invincible = 1;
}

void action_player(all_t *all)
{
    // loose(all);
    anim_player(all);
    get_hit(all);
    // no_more_invincible(all);
    // level_up(all);
    move(&all->player.sp);
    collisions(&all->player.sp, all);
    win(all);
}

player_t create_player(sfClock *clock)
{
    player_t res = {0};
    res.sp = sp_create(P_PLAYER, clock);
    // res.invicibility_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    return res;
}

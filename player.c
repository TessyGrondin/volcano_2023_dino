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
    all->player.last != all->player.anim) {
        if (all->player.sp.frame == 3) {
            rect.left = all->player.anim * 32 * 4;
            all->player.sp.frame = 0;
        } else {
            rect.left += 32;
            all->player.sp.frame++;
        }
        sfSprite_setTextureRect(all->player.sp.sp, rect);
        all->player.sp.lat = timing;
    }

}

void no_more_invincible(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    if (timing - all->player.invicibility_time >= 0.5 &&
    all->player.invincible == 1) {
        all->player.invincible = 0;
        all->player.invicibility_time = timing;
    }
}

sprite_t sp_create(char *name, char *path, sfClock *cl)
{
    sfIntRect r = {32, 0, 32, 32};
    sprite_t res;
    if (my_strcmp(name, "sword") == 0)
        res.value = 1.5;
    else if (my_strcmp(name, "fire") == 0 || my_strcmp(name, "wheel") == 0) {
        res.value = 6;
        r = (sfIntRect){64, 0, 64, 64};
    } else
        res.value = 1;
    res.name = my_strdup(name);
    res.sp = sfSprite_create();
    res.tex = sfTexture_createFromFile(path, NULL);
    res.frame = 0;
    res.lat = sfTime_asSeconds(sfClock_getElapsedTime(cl));
    sfSprite_setTexture(res.sp, res.tex, sfFalse);
    sfSprite_setTextureRect(res.sp, r);
    return res;
}

void level_up(all_t *all)
{
    int attrand = rand() % 6 + 1;
    int defrand = rand() % 6 + 1;
    if (all->player.exp == 100) {
        all->player.level += 1;
        all->player.attack += attrand;
        all->player.def += defrand;
        all->player.exp = 0;
        sfSound_play(all->sounds.levelup);
    }
    is_hp_ring(&all->player);
}

void action_player(all_t *all)
{
    loose(all);
    anim_player(all);
    get_hit(all);
    no_more_invincible(all);
    level_up(all);
    move(&all->player);
    collisions(&all->player, all);
    win(all);
}

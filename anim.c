/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** anim
*/

#include "include/testmap.h"

void play_animation(enti_t *entit, all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    sfIntRect rect = sfSprite_getTextureRect(entit->sp.sp);
    anim_player(all);
    if (timing - entit->sp.lat >= 0.15 || all->force_anim_change) {
        if (entit->sp.frame == 3) {
            rect.left = entit->anim * 32 * 4;
            entit->sp.frame = 0;
        } else {
            rect.left += 32;
            entit->sp.frame++;
        }
        sfSprite_setTextureRect(entit->sp.sp, rect);
        entit->sp.lat = timing;
    }
}

enti_t entit_create(sfClock *clock, char *pathname, char *name)
{
    sfTime time = sfClock_getElapsedTime(clock);
    enti_t res;
    res.sp = sp_create(name, pathname, clock);
    init_state(&res);
    res.invicibility_time = sfTime_asSeconds(time);
    if (my_strcmp(name, "player") == 0) {
        res.sword = sp_create("sword", P_SWORD, clock);
        res.ball = sp_create("fire", P_FIRE, clock);
        res.wheel = sp_create("wheel", P_WHEEL, clock);
    }
    return res;
}

void draw_sprite(all_t *all)
{
    for (int i = 0; all->ent[i].sp.sp != NULL; i++) {
        if (all->ent[i].alive == 1)
            sfRenderWindow_drawSprite(all->win, all->ent[i].sp.sp, NULL);
    }
    sfRenderWindow_drawSprite(all->win, all->player.sp.sp, NULL);
    set_last_npc(all);
    sfRenderWindow_drawSprite(all->win, all->npc.self.sp, NULL);
    draw_wheel(all);
    if (all->player.use_fire)
        sfRenderWindow_drawSprite(all->win, all->player.ball.sp, NULL);
}

void anim_everyone(all_t *all)
{
    for (int i = 0; all->ent[i].sp.sp != NULL; i++)
        play_animation(&all->ent[i], all);
    for (int i = 0; all->ent[i].sp.sp != NULL; i++)
        move(&all->ent[i]);
    if (all->npc.self.sp != NULL) {
        redirection_animation(&all->npc, all);
        interaction(&all->npc, all);
        play_dialogue(&all->npc, all);
    }
    monster_collisions(all);
    anim_fire(all, all->orientation);
    anim_wheel(all);
    fire_hit(all);
    hit_wheel(all);
    map_borders(all);
    all->force_anim_change = 0;
}

void auto_animation(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    if (!all->charged || all->is_end == 1) return;
    if (timing - all->move >= 2) {
        for (int i = 0; all->ent[i].sp.sp != NULL; i++) {
            all->ent[i].anim = rand() % 20;
            all->ent[i].anim = ((all->ent[i].anim) > 9) ? 0 : all->ent[i].anim;
            all->ent[i].anim = ((all->ent[i].anim) == 1) ? 0 : all->ent[i].anim;
            all->ent[i].sp.frame = 3;
        }
        all->move = timing;
        all->force_anim_change = 1;
    }
    anim_everyone(all);
}

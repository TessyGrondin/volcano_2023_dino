/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** loop
*/

#include "include/testmap.h"

void draw_textBox(all_t *all, text_box_t text_box)
{
    sfRenderWindow_drawSprite(all->win, text_box.sp.sp, NULL);
    sfRenderWindow_drawText(all->win, text_box.text, NULL);
}

void intro(all_t *all)
{
    char *tmp[] = {"My powers are weakening my child.", "As the one who can here me,", "please bring me energy", "so I can resplenish my strengh.", NULL};

    if (all->first_cine == sfFalse) {
        if (all->timer > (5 * 60)) {
            all->first_cine = sfTrue;
            all->timer = 0;
        }
        sfRenderWindow_drawSprite(all->win, all->cine1.sp, NULL);
    } else if (all->first_text == sfFalse && all->first_cine == sfTrue) {
        if (all->timer > (5 * 60)) {
            all->first_text = sfTrue;
            all->timer = 0;
        }
        sfText_setString(all->text1, "Since the beginning of things,");
        sfRenderWindow_drawText(all->win, all->text1, NULL);
        if (all->timer > 2 * 60) {
            sfText_setString(all->text2, "Gods have been using various forms to provide.");
            sfRenderWindow_drawText(all->win, all->text2, NULL);
        }
    } else if (all->second_cine == sfFalse && all->first_cine == sfTrue && all->first_text == sfTrue) {
        if (all->timer > (5 * 60)) {
            all->second_cine = sfTrue;
            all->timer = 0;
        }
        sfRenderWindow_drawSprite(all->win, all->cine2.sp, NULL);
    } else if (all->seconde_text == sfFalse && all->first_cine == sfTrue && all->first_text == sfTrue && all->second_cine == sfTrue) {
        if (all->timer > (9 * 60)) {
            all->seconde_text = sfTrue;
            all->timer = 0;
        }
        sfText_setPosition(all->text1, (sfVector2f){100, 110});
        sfText_setString(all->text1, "By their side, mythical creatures.");
        sfRenderWindow_drawText(all->win, all->text1, NULL);
        if (all->timer > 2 * 60) {
            sfText_setString(all->text2, "Some know them as unicorns...");
            sfText_setPosition(all->text2, (sfVector2f){100, 130});
            sfRenderWindow_drawText(all->win, all->text2, NULL);
        }
        if (all->timer > 4 * 60) {
            sfText_setString(all->text3, "But more recently,");
            sfText_setPosition(all->text3, (sfVector2f){100, 150});
            sfRenderWindow_drawText(all->win, all->text3, NULL);
        }
        if (all->timer > 6 * 60) {
            sfText_setString(all->text4, "people have been calling them cerathosaurus...");
            sfText_setPosition(all->text4, (sfVector2f){100, 170});
            sfRenderWindow_drawText(all->win, all->text4, NULL);
        }
    } else if (all->first_cine == sfTrue && all->first_text == sfTrue && all->second_cine == sfTrue && all->seconde_text == sfTrue) {
        sfMusic_stop(all->sounds.menu_mus);
        main_music_manager(&all->sounds, all->sounds.game_mus);
        read_entrances(all);
        get_all_layers(all);
        all->player.last = all->player.sp.anim;
        all->player.last_move = is_move(all->player.sp.anim, all->player.last_move);
        sfSprite_setScale(all->player.sp.sp, (sfVector2f){1, 1});
        sfSprite_setOrigin(all->player.sp.sp, (sfVector2f){0, 0});
        action_player(all);
        map_draw(all);

        sfText_setString(all->altar.text_box.text, tmp[all->altar.altar_dialog_index]);

        draw_textBox(all, all->altar.text_box);

        if (all->timer >= (5 * 60)) {
            if (all->altar.altar_dialog_index == 3) {
                all->timer = 0;
                all->altar.altar_dialog_index = 0;
                all->states = GAME;
                return;
            }
            all->timer = 0;
            all->altar.altar_dialog_index++;
            sfText_setString(all->altar.text_box.text, tmp[all->altar.altar_dialog_index]);
        }
    }
    all->timer++;
}

void play_animation_load(sprite_t *entit, all_t *all, int width)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    sfIntRect rect = sfSprite_getTextureRect(entit->sp);
    anim_player(all);
    if (timing - entit->lat >= 0.15 || all->force_anim_change) {
        if (entit->frame == 7) {
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

void display_loading(all_t *all)
{
    play_animation_load(&all->load, all, 64);
    sfSprite_setScale(all->load.sp, (sfVector2f){2, 2});
    sfText_setString(all->text3, "Loading...");
    sfText_setPosition(all->text3, (sfVector2f){1000, 1200});
    sfRenderWindow_drawSprite(all->win, all->cine1.sp, sfFalse);
    sfRenderWindow_drawSprite(all->win, all->load.sp, sfFalse);
    sfRenderWindow_drawText(all->win, all->text3, sfFalse);
}

void game_loop(all_t *all, sfThread *map_load)
{
    if (!all->can_play) {
        display_loading(all);
        sfThread_launch(map_load);
    }
    else {
        sfMusic_stop(all->sounds.menu_mus);
        main_music_manager(&all->sounds, all->sounds.game_mus);
        read_entrances(all);
        catch_input(all);
        action_player(all);
        auto_animation(all);
        alea(all);
        map_draw(all);

        if (all->current_map == 7) {
            if (is_colliding(&all->player.sp, &all->altar.sp)) {
                if (all->player.offering > 0) {
                    sfText_setString(all->altar.text_box.text, "offering");
                    all->altar.offering += all->player.offering;
                    all->player.offering = 0;
                    all->player.give_offering = sfTrue;
                } else if (all->player.give_offering == sfFalse)
                    sfText_setString(all->altar.text_box.text, "find me more offering");

                draw_textBox(all, all->altar.text_box);

                if (all->player.give_offering == sfTrue && all->timer > (2 * 60)) {
                    all->player.give_offering = sfFalse;
                    all->timer = 0;
                }
                all->timer++;
            }
        }
    }
}

sfSound *create_sound(char *path)
{
    sfSound *res = sfSound_create();
    sfSoundBuffer *tmp = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(res, tmp);
    return res;
}

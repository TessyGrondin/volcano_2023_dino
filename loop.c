/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** loop
*/

#include "include/testmap.h"

char *get_str_from_nbr(int nb)
{
    int E = 10;
    char *result = NULL;
    int i = 0;
    if (nb < 0) {
        nb = nb * (-1);
        result = my_append(result,'-');
        i++;
    }
    while (nb / E > 9) {
        E = E * 10;
    }
    for (; E >= 1 && i < 11; i++) {
        result = my_append(result, (nb / E + 48)) ;
        nb = nb % E;
        E = E / 10;
    }
    result[i] = '\0';
    return result;
}

char *concat_all(char *level, char *def, char *att)
{
    char *first = my_strdup("Level : ");
    char *sec = my_strdup("\natt. = ");
    char *third = my_strdup("\ndef. = ");
    char *res = my_strcat(first, level);
    res = my_strcat(res, my_strcat(sec, att));
    res = my_strcat(res, my_strcat(third, def));
    return res;
}

void draw_textBox(all_t *all, text_box_t text_box)
{
    sfRenderWindow_drawSprite(all->win, text_box.sp.sp, NULL);
    sfRenderWindow_drawText(all->win, text_box.text, NULL);
}

void intro(all_t *all)
{
    char *tmp[] = {"My powers are weakening my child.", "As the one who can here me,", "please bring me energy", "so I can resplenish my strengt.", NULL};

    sfMusic_stop(all->sounds.menu_mus);
    main_music_manager(&all->sounds, all->sounds.game_mus);
    read_entrances(all);
    get_all_layers(all);

    anim_player(all);

    map_draw(all);
    sfRenderWindow_drawSprite(all->win, all->altar.sp.sp, NULL);

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
        // sfText_setString(all->altar.text_box.text, tmp[all->altar.altar_dialog_index]);
    all->timer++;
    }
}

void game_loop(all_t *all)
{
    sfMusic_stop(all->sounds.menu_mus);
    main_music_manager(&all->sounds, all->sounds.game_mus);
    read_entrances(all);
    get_all_layers(all);
    catch_input(all);
    action_player(all);
    auto_animation(all);
    alea(all);
    map_draw(all);

    if (all->current_map == 4) {
        sfRenderWindow_drawSprite(all->win, all->altar.sp.sp, NULL);
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

sfSound *create_sound(char *path)
{
    sfSound *res = sfSound_create();
    sfSoundBuffer *tmp = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(res, tmp);
    return res;
}

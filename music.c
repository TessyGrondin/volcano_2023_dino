/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** music.
*/

#include "include/testmap.h"

sound_t get_all_sounds(void)
{
    sound_t res;
    res.game_mus = sfMusic_createFromFile(P_OVERWORLD);
    res.menu_mus = sfMusic_createFromFile(P_MENU_MUSIC);
    res.loose_mus = sfMusic_createFromFile(P_LOOSE);
    res.win_mus = sfMusic_createFromFile(P_WIN);
    res.hit = create_sound(P_HIT);
    res.button_sound = create_sound(P_BUTTON_SOUND);
    return res;
}

void main_music_manager(sound_t *sounds, sfMusic *mus)
{
    if (sfMusic_getStatus(mus) == sfPlaying)
        return;
    (void)sounds;
    sfMusic_setLoop(mus, sfTrue);
    sfMusic_play(mus);
}


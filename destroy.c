/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** destroy
*/

#include "include/testmap.h"

void destroy_menu_and_sounds(all_t *all)
{
    sfSprite_destroy(all->menu.start.look.sp);
    sfTexture_destroy(all->menu.start.look.tex);
    sfSprite_destroy(all->menu.bg.sp);
    sfTexture_destroy(all->menu.bg.tex);
    sfMusic_destroy(all->sounds.game_mus);
    sfMusic_destroy(all->sounds.win_mus);
    sfMusic_destroy(all->sounds.loose_mus);
    sfMusic_destroy(all->sounds.menu_mus);
    sfSound_destroy(all->sounds.button_sound);
    sfSound_destroy(all->sounds.hit);
}

void destroy_map(map_t *map)
{
    for (int i = 0; i != map->nb_layer; i++)
        sfVertexArray_destroy(map->vert[i]);
    free(map->vert);
    for (int i = 0; map->tiles[i]; i++)
        free(map->tiles[i]);
    free(map->tiles);
    for (int i = 0; i < 600; i++) {
        sfRectangleShape_destroy(map->collisions[i].rect);
    }
    free(map->collisions);
    sfTexture_destroy(map->tileset);
}

void destroy_all(all_t *all)
{
    destroy_menu_and_sounds(all);
    if (!all->e_menu)
        return;
    sfSprite_destroy(all->altar.sp.sp);
    sfTexture_destroy(all->altar.sp.tex);
    sfSprite_destroy(all->altar.text_box.sp.sp);
    sfTexture_destroy(all->altar.text_box.sp.tex);
    sfText_destroy(all->altar.text_box.text);

    sfSprite_destroy(all->player.sp.sp);
    sfTexture_destroy(all->player.sp.tex);
    sfRenderWindow_destroy(all->win);
    sfView_destroy(all->view);
    destroy_map(&all->map);
    sfSprite_destroy(all->end.sp);
    sfTexture_destroy(all->end.tex);
}

void empty_level(all_t *all)
{
    for (int i = 0; i != all->map.nb_layer; i++)
        sfVertexArray_destroy(all->map.vert[i]);
    for (int i = 0; all->map.tiles[i]; i++)
        for (int j = 0; j != 600; j++)
            all->map.tiles[i][j] = -1;
    for (int i = 0; i != 600; i++)
        all->map.collisions[i].state = sfFalse;
    for (int i = 0; all->enemies[i].sp != NULL; i++) {
        sfTexture_destroy(all->enemies[i].tex);
        sfSprite_destroy(all->enemies[i].sp);
        all->enemies[i].sp = NULL;
    }
    for (int i = 0; all->target[i].sp.sp != NULL; i++) {
        sfTexture_destroy(all->target[i].sp.tex);
        sfSprite_destroy(all->target[i].sp.sp);
        all->target[i].sp.sp = NULL;
    }
}

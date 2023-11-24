/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** destroy
*/

#include "include/testmap.h"

void destroy_npc(all_t *all)
{
    sfTexture_destroy(all->npc.self.tex);
    sfSprite_destroy(all->npc.self.sp);
    sfTexture_destroy(all->npc.dialogue.tex);
    sfSprite_destroy(all->npc.dialogue.sp);
    can_free(all->npc.self.name);
    can_free(all->npc.dialogue.name);
    all->npc.self.sp = NULL;
}

void destroy_menu_and_sounds(all_t *all)
{
    sfSprite_destroy(all->menu.start.look.sp);
    sfTexture_destroy(all->menu.start.look.tex);
    can_free(all->menu.start.look.name);
    sfSprite_destroy(all->menu.bg.sp);
    sfTexture_destroy(all->menu.bg.tex);
    can_free(all->menu.bg.name);
    sfMusic_destroy(all->sounds.game_mus);
    sfMusic_destroy(all->sounds.win_mus);
    sfMusic_destroy(all->sounds.loose_mus);
    sfMusic_destroy(all->sounds.menu_mus);
    sfSound_destroy(all->sounds.button_sound);
    sfSound_destroy(all->sounds.hit);
    sfSound_destroy(all->sounds.levelup);
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
        sfRectangleShape_destroy(map->road[i].rect);
    }
    free(map->collisions);
    free(map->road);
    sfTexture_destroy(map->tileset);
}

void destroy_all(all_t *all)
{
    destroy_menu_and_sounds(all);
    if (!all->e_menu)
        return;
    sfRenderWindow_destroy(all->win);
    sfView_destroy(all->view);
    for (int i = 0; all->life[i]; i++)
        sfRectangleShape_destroy(all->life[i]);
    free(all->life);
    destroy_map(&all->map);
    if (all->npc.self.sp)
        destroy_npc(all);
    sfSprite_destroy(all->end.sp);
    sfTexture_destroy(all->end.tex);
    can_free(all->end.name);
}

void empty_level(all_t *all)
{
    for (int i = 0; i != all->map.nb_layer; i++)
        sfVertexArray_destroy(all->map.vert[i]);
    for (int i = 0; all->map.tiles[i]; i++)
        for (int j = 0; j != 600; j++)
            all->map.tiles[i][j] = -1;
    for (int i = 0; i != 600; i++) {
        all->map.collisions[i].state = sfFalse;
        all->map.road[i].state = sfFalse;
    }
    for (int i = 0; all->ent[i].sp.sp != NULL; i++) {
        sfTexture_destroy(all->ent[i].sp.tex);
        sfSprite_destroy(all->ent[i].sp.sp);
        can_free(all->ent[i].sp.name);
        all->ent[i].sp.sp = NULL;
    }
    if (all->npc.self.sp)
        destroy_npc(all);
}

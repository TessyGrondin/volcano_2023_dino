/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** map_load
*/

#include "include/testmap.h"

void make_quads(map_t *map, sfVector2u ts, sfVector2i pos, int layer)
{
    int tile_number = map->tiles[layer][pos.x + pos.y * map->width];
    sfVector2u size = sfTexture_getSize(map->tileset);
    int tu = tile_number % (size.x / ts.x);
    int tv = tile_number / (size.x / ts.x);
    sfVertex *qua;
    if (map->tiles[layer][pos.y * map->width + pos.x] == -1)
        return;
    qua = sfVertexArray_getVertex(map->vert[layer], \
    (pos.x + pos.y * map->width) * 4);
    qua[0].position = (sfVector2f){pos.x * ts.x, pos.y * ts.y};
    qua[1].position = (sfVector2f){(pos.x + 1) * ts.x, pos.y * ts.y};
    qua[2].position = (sfVector2f){(pos.x + 1) * ts.x, (pos.y + 1) * ts.y};
    qua[3].position = (sfVector2f){pos.x * ts.x, (pos.y + 1) * ts.y};
    qua[0].texCoords = (sfVector2f){tu * ts.x, tv * ts.y};
    qua[1].texCoords = (sfVector2f){(tu + 1) * ts.x, tv * ts.y};
    qua[2].texCoords = (sfVector2f){(tu + 1) * ts.x, (tv + 1) * ts.y};
    qua[3].texCoords = (sfVector2f){tu * ts.x, (tv + 1) * ts.y};
}

void fillvert(map_t *map, sfVector2u tile_size, int layer)
{
    for (unsigned int i = 0; i < map->width; i++) {
        for (unsigned int j = 0; j < map->height; j++)
            make_quads(map, tile_size, (sfVector2i){i, j}, layer);
    }
}

sfBool map_load(map_t *map, char *path, sfVector2u tile_size)
{
    if (!sfTexture_createFromFile(path, NULL))
        return sfFalse;
    map->tileset = sfTexture_createFromFile(path, NULL);
    for (int i = 0; i != map->nb_layer; i++) {
        map->vert[i] = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(map->vert[i], sfQuads);
        sfVertexArray_resize(map->vert[i], map->width * map->height * 4);
        fillvert(map, tile_size, i);
    }
    fill_all_collisions(map);
    return sfTrue;
}

void alea(all_t *all)
{
    if (all->altar.alea_cendre == sfFalse && all->altar.offering >= 5) {
        all->altar.alea_cendre = sfTrue;
        printf("alea cendre\n");
        // do alea de cendre
    }
    if (all->altar.alea_gli_ter == sfFalse && all->altar.offering >= 10) {
        all->altar.alea_gli_ter = sfTrue;
        printf("alea glissement de terrain\n");
        // do alea de glissement de terrain + lave
    }
    if (all->altar.alea_lave == sfFalse && all->altar.offering >= 15) {
        all->altar.alea_lave = sfTrue;
        printf("alea lave\n");
        // do alea de lave
    }
    if (all->altar.offering >= 20)
        win(all);
}

void draw_textBox(all_t *all, text_box_t text_box)
{
    sfRenderWindow_drawSprite(all->win, text_box.sp.sp, NULL);
    sfRenderWindow_drawText(all->win, text_box.text, NULL);
}

void map_draw(all_t *all)
{
    sfRenderStates states = {0};
    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    if (all->charged == 1 && all->is_end == 0) {
        states.texture = all->map.tileset;
        sfRenderWindow_drawVertexArray(all->win, all->map.vert[GROUND], &states);
        draw_sprite(all);
        sfRenderWindow_drawVertexArray(all->win, all->map.vert[DECORS], &states);

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
}

        // if (all->npc.can_dialogue == 1)
        //     sfRenderWindow_drawSprite(all->win, all->npc.dialogue.sp, NULL);
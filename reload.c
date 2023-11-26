/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** reaload
*/

#include "include/testmap.h"

char **getlvl_load(const char *pathname)
{
    int op = open(pathname, O_RDONLY);
    struct stat buf;
    char *data = NULL;
    char **splits = NULL;
    int st = stat(pathname, &buf);
    int size = 0;
    if (st == -1 || op == -1)
        return NULL;
    data = malloc(sizeof(char) * (buf.st_size + 1));
    size = read(op, data, buf.st_size);
    if (size == -1)
        return NULL;
    data[buf.st_size] = '\0';
    splits = my_str_to_word_array(data, ",\n");
    free(data);
    return splits;
}

void convert_to_int(char **src, all_t *all, int layer)
{
    if (src == NULL)
        return;
    for (int i = 0; src[i]; i++)
        all->map.tiles[layer][i] = my_getnbr(src[i]);
    all->map.tiles[layer][my_tablen((const char **)src)] = -2;
}

void reload(all_t *all)
{
    char **ref = NULL;
    for (int i = 0; maps[all->current_map][i]; i++) {
        ref = getlvl_load(maps[all->current_map][i]);
        convert_to_int(ref, all, i);
        freer(ref);
    }
    all->map.tiles[all->map.nb_layer] = NULL;
    if (!map_load(&all->map, P_TILESET, (sfVector2u){16, 16}))
        return;
    for (int i = 0; all->target[i].sp.sp; i++)
        all->target[i].alive = sfTrue;
    spone_monster(all);
    all->charged = 1;
}

void make_base_material(all_t *res)
{
    res->win = sfRenderWindow_create((sfVideoMode) {1080, 720, 32},\
    "The way of Fire", sfClose | sfResize, NULL);
    res->view = sfView_create();
    sfView_setCenter(res->view, (sfVector2f){(30 * 16 / 2), (20 * 16 / 2)});
    sfView_setSize(res->view, (sfVector2f){(30 * 16), (20 * 16)});
    sfRenderWindow_setView(res->win, res->view);
}

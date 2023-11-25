/*
** EPITECH PROJECT, 2023
** work
** File description:
** testmap
*/

#pragma once

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Audio/Listener.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundRecorder.h>
    #include <SFML/Audio/SoundBufferRecorder.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/SoundStream.h>
    #include <SFML/Config.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include "my.h"
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <time.h>
    #include "layers_header.h"
    #include "assets_header.h"

    typedef struct {
        sfRectangleShape *rect;
        sfBool state;
    } collision_t;

    typedef struct {
        sfVertexArray **vert;
        sfTexture *tileset;
        int **tiles;
        int nb_layer;
        unsigned int width;
        unsigned int height;
        collision_t *collisions;
    } map_t;

    typedef struct {
        sfSprite *sp;
        sfTexture *tex;
        int frame;
        float lat;
        int anim;
    } sprite_t;

    typedef struct {
        sprite_t sp;
    } ennemy_t;

    typedef struct {
        sprite_t sp;
        sfBool alive;
        int map;
    } target_t;

    typedef struct {
        sprite_t sp;
        sfText *text;
    } text_box_t;

    typedef struct {
        sprite_t sp;
        text_box_t text_box;
        int offering;
    } altar_t;

    typedef struct {
        sprite_t sp;
        sfBool bite;
        int last;
        int last_move;
        int orientation;
        int offering;
    } player_t;

    enum layer {
        GROUND,
        DECORS,
        BIOM,
        ENTRANCES,
        COLLISION,
        SPAWN
    };

    enum animation {
        IDDLE,
        ATT_S,
        LEFT,
        RIGHT,
        DOWN,
        UP,
        ATT_B,
        ATT_F
    };

    typedef struct {
        sfMusic *game_mus;
        sfMusic *menu_mus;
        sfMusic *loose_mus;
        sfMusic *win_mus;
        sfSound *hit;
        sfSound *button_sound;
    } sound_t;

    typedef struct button_s {
        sprite_t look;
        int state;
    } button_t;

    typedef struct menu_s {
        sprite_t bg;
        button_t start;
    } menu_t;

    typedef struct {
        sfRenderWindow *win;
        sfEvent event;
        map_t map;
        player_t player;
        sfView *view;
        sfClock *clock;
        sprite_t *enemies;
        target_t *target;
        sprite_t end;
        altar_t altar;
        sound_t sounds;
        menu_t menu;
        int charged;
        float move;
        int force_anim_change;
        int current_map;
        int is_end;
        int e_menu;
        int placed_target;
    } all_t;

    player_t create_player(sfClock *clock);
    sfBool collide_bite(sfFloatRect rect, sprite_t *other);
    void use_bite(player_t *player, all_t *all);
    void bite_left(player_t *player, target_t *target);
    void bite_right(player_t *player, target_t *target);
    void bite_up(player_t *player, target_t *target);
    void bite_down(player_t *player, target_t *target);
    void find_last_move(player_t *player);
    altar_t create_altar(char *path, sfClock *cl);

    int *getlvl(const char *pathname);
    all_t init_all(void);
    sfBool map_load(map_t *map, char *path, sfVector2u tile_size);
    void map_draw(all_t *all);
    map_t initmap(void);
    void get_all_layers(all_t *all);
    void destroy_all(all_t *all);
    void draw_sprite(all_t *all);
    void auto_animation(all_t *all);
    void move(sprite_t *sprite);
    void catch_input(all_t *all);
    void anim_player(all_t *all);
    void spone_monster(all_t *all);
    void map_borders(all_t *all);
    sprite_t sp_create(char *path, sfClock *cl);
    int is_colliding(sprite_t *self, sprite_t *other);
    void get_hit(all_t *all);
    void collisions(sprite_t *ent, all_t *all);
    int is_move(int anim, int self);
    void anim_npc(target_t  *target, all_t *all);
    void empty_level(all_t *all);
    void read_entrances(all_t *all);
    void change_map(all_t *all, int new_map);
    sfBool create_collisions(collision_t *array);
    void fill_all_collisions(map_t *map);
    void monster_collisions(all_t *all);
    void reload(all_t *all);
    void loose(all_t *all);
    void action_player(all_t *all);
    void win(all_t *all);
    void main_music_manager(sound_t *sounds, sfMusic *mus);
    sound_t get_all_sounds(void);
    void make_base_material(all_t *res);
    int button_click(all_t *all);
    void button_highlight(all_t *all);
    void display_button(button_t *button, all_t *all, sfVector2f pos);
    menu_t get_menu(sfClock *clock);
    void display_menu(all_t *all);
    void game_loop(all_t *all);
    sfSound *create_sound(char *path);

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
        collision_t *road;
    } map_t;

    typedef struct {
        char *name;
        sfSprite *sp;
        sfTexture *tex;
        int value;
        int frame;
        float lat;
    } sprite_t;

    typedef struct {
        sprite_t sp;
        sprite_t sword;
        sprite_t ball;
        sprite_t wheel;
        int level;
        int alive;
        int invincible;
        float invicibility_time;
        int use_sword;
        int use_fire;
        int use_wheel;
        int hp;
        int attack;
        int def;
        int exp;
        int anim;
        int last_move;
        int last;
        int rings;
        int max_hp;
    } enti_t;

    enum layer {
        GROUND,
        ROAD,
        DECORS,
        ENTRANCES,
        COLLISION,
        SPONE
    };

    enum animation {
        IDDLE,
        ATT_S,
        LEFT,
        RIGHT,
        DOWN,
        UP,
        DOWNLEFT,
        DOWNRIGHT,
        UPLEFT,
        UPRIGHT,
        ATT_B,
        ATT_F
    };

    typedef struct {
        sfMusic *game_mus;
        sfMusic *menu_mus;
        sfMusic *loose_mus;
        sfMusic *win_mus;
        sfSound *hit;
        sfSound *levelup;
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
        sprite_t self;
        sprite_t dialogue;
        int can_dialogue;
    } npc_t;

    typedef struct {
        sfRenderWindow *win;
        sfEvent event;
        map_t map;
        enti_t player;
        sfView *view;
        sfClock *clock;
        enti_t *ent;
        npc_t npc;
        sfRectangleShape **life;
        sprite_t end;
        sound_t sounds;
        menu_t menu;
        sfText *stats;
        int charged;
        float move;
        int force_anim_change;
        int orientation;
        int current_map;
        int is_end;
        int e_menu;
    } all_t;

    int *getlvl(const char *pathname);
    all_t init_all(void);
    sfBool map_load(map_t *map, char *path, sfVector2u tile_size);
    void map_draw(all_t *all);
    map_t initmap(void);
    void get_all_layers(all_t *all);
    void destroy_all(all_t *all);
    enti_t entit_create(sfClock *clock, char *pathname, char *name);
    void draw_sprite(all_t *all);
    void auto_animation(all_t *all);
    void move(enti_t *ent);
    void catch_input(all_t *all);
    void anim_player(all_t *all);
    void spone_monster(all_t *all);
    void map_borders(all_t *all);
    sprite_t sp_create(char *name, char *path, sfClock *cl);
    void use_sword(enti_t *player, all_t *all);
    int is_colliding(sprite_t *self, sprite_t *other);
    void is_alive(all_t *all);
    void draw_life_barre(all_t *all);
    sfRectangleShape **create_life_barre(void);
    void get_hit(all_t *all);
    int fire_hit(all_t *all);
    void fire_move(enti_t *player);
    void anim_fire(all_t *all, int orientation);
    void catch_fire_one(all_t *all);
    void collisions(enti_t *ent, all_t *all);
    void find_last_move(enti_t *player);
    int is_move(int anim, int self);
    void sword_left(enti_t *player, enti_t *monster);
    void sword_right(enti_t *player, enti_t *monster);
    void sword_up(enti_t *player, enti_t *monster);
    void sword_down(enti_t *player, enti_t *monster);
    void npc_range(all_t *all, int index);
    npc_t npc_create(char *name, all_t *all);
    void interaction(npc_t *npc, all_t *all);
    void anim_npc(npc_t *npc, all_t *all);
    void anim_dragon(npc_t *dragon, all_t *all);
    void anim_chest(npc_t *chest, all_t *all);
    void play_dialogue(npc_t *npc, all_t *all);
    void anim_wheel(all_t *all);
    void draw_wheel(all_t *all);
    void hit_wheel(all_t *all);
    void check_hp(enti_t *ent, enti_t *plr);
    void empty_level(all_t *all);
    void read_entrances(all_t *all);
    void change_map(all_t *all, int new_map);
    sfBool create_collisions(collision_t *array);
    void fill_all_collisions(map_t *map);
    void npc_collisions(all_t *all);
    void collision_left(enti_t *ent, all_t *all);
    void collision_right(enti_t *ent, all_t *all);
    void collision_up(enti_t *ent, all_t *all);
    void collision_down(enti_t *ent, all_t *all);
    sfVector2f inverse_move(enti_t *ent);
    void road_collisions(enti_t *ent, all_t *all);
    void monster_collisions(all_t *all);
    void reload(all_t *all);
    void redirection_animation(npc_t *npc, all_t *all);
    void init_state(enti_t *res);
    void set_chest(all_t *all);
    void set_last_npc(all_t *all);
    void add_ring(all_t *all);
    void give_hp(enti_t *player);
    void is_hp_ring(enti_t *player);
    sfBool is_def(int ring);
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

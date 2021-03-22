/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** structs
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct vec3 {
    int x;
    int y;
    int z;
} vec3_t;

typedef struct settings {
    char *name;
    char *value;
} settings_t;

typedef struct ennemy {
    int id;
    int skin_id;
    int type;
    int health;
    int armor;
    int speed;
    int credit;
    pos_t pos;
    pos_t pixel;
    pos_t last_dir;
    sfClock *timer;
    sfSprite *skin;
    sfSprite *dead;
    char *skin_path;
    char *dead_path;
} ennemy_t;

typedef struct map_block {
    int x;
    int y;
    int layer;
    int property;
    int texture;
} map_block_t;

typedef struct map {
    char *path;
    char *name;
    pos_t size;
    char **vmap;
    sfSprite ****sp_map;
    map_block_t *blocks;
    int block_count;
} map_t;

typedef struct scenario_detail {
    map_t *map;
    char *mpath;
    int wave_count;
    int credit;
    ennemy_t *ennemy_dic;
    int ennemy_count;
    int difficulty;
} scen_detail_t;

typedef struct scenario {
    char *path;
    char *name;
    int valid;
    scen_detail_t detail;
} scenario_t;

typedef struct turrets {
    int id;
    int type;
    pos_t pos;
    int range;
    int level;
    int price;
    int damage;
    int fire_pos;
    int fire_rate;
    sfSprite *icon;
    sfSprite *base;
    sfSprite *head;
    sfSprite *projectile;
    int last_target;
    int target_type;
    char *head_path;
    char *proj_path;
} turrets_t;

typedef struct turret_info {
    sfSprite *background;
    struct button *sell;
    struct button *upgrade;
    struct button *close;
    sfText *id;
    sfText *level;
    sfText *damage;
    sfText *fire_rate;
    sfText *range;
} turret_info_t;

enum in_game_state {
    NORMAL,
    TEK_TREE,
    INFORM,
};

enum setting_step {
    SET_GRAPH,
    SET_KEYS,
    SET_SOUND,
    SET_GUI,
    SET_HOME,
};

enum win_step {
    HOME,
    SETTINGS,
    SELECTOR,
    EDITOR_MENU,
    EDITOR_ENGINE,
    GAME,
    PAUSE,
    G_SETTINGS,
    GAME_OVER,
    GAME_WIN,
    OUT,
};

typedef struct sounds {
    sfMusic *ambiance;
    sfMusic *wind;
    sfMusic *alert;
    sfMusic *siren;
    sfMusic *intro;
    sfMusic *game_win;
    sfMusic *game_over;
    sfSoundBuffer *b_laser;
    sfSoundBuffer *b_wav;
    sfSoundBuffer *b_btn;
    sfSoundBuffer *b_explo;
    sfSoundBuffer *b_imp;
    sfSoundBuffer *b_death;
    sfSound *laser;
    sfSound *wave_end;
    sfSound *btn_press;
    sfSound *explosion;
    sfSound *impossible;
    sfSound *bitter_death;
} sound_t;

typedef struct keymap {
    sfKeyCode w;
    sfKeyCode s;
    sfKeyCode a;
    sfKeyCode d;
} keymap_t;

typedef struct keys {
    int tab;
    int space;
    int mouse;
    int mv_up;
    int mv_left;
    int mv_down;
    int mv_right;
} keys_t;

typedef struct slider {
    int value;
    sfText *text;
    sfText *digit;
    sfVector2f coo;
    sfSprite *p_box;
    sfSprite *bar_empty;
    sfSprite *bar_filled;
    struct button *cursor;
} slider_t;

typedef struct start_menu {
    int scenario_count;
    scenario_t *scenarios;
    map_t *maps;
    int map_count;
    sfSprite *title;
    sfSprite *background;
    struct button *transp;
    struct button *play_b;
    struct button *exit_b;
    struct button *sett_b;
    struct button *abot_b;
    struct button *edit_b;
} start_menu_t;

typedef struct selec_menu {
    int select;
    sfSprite *map_back;
    sfSprite *background;
    struct button *home;
    struct button *play;
    struct button *transp1;
    struct button *transp2;
    sfText *credits;
    sfText *sce_name;
    sfText *en_count;
    sfText *wav_count;
    sfText *difficulty;
    struct button **scenarios_btn;
} selec_menu_t;

typedef struct editor_eng {
    int layer;
    int select;
    sfText *layer_t;
    pos_t last_mouse;
    sfSprite *cursor;
    sfSprite *background;
    struct button *water;
    struct button *path;
    struct button *erase;
    struct button *start;
    struct button *end;
    struct button *tree1;
    struct button *tree2;
    struct button *tree3;
    struct button *hitbox;
    struct button *useless;
    struct button *layer_up;
    struct button *layer_down;
    map_t map;
} editor_eng_t;

typedef struct editor_menu {
    int select;
    sfSprite *background;
    struct button *home;
    struct button *build;
    struct button *transp1;
    struct button *transp2;
    struct button *new_map;
    struct button **maps_btn;
} editor_menu_t;

typedef struct end_menu {
    sfText *condition;
    sfSprite *background;
    struct button *home;
    struct button *transp;
    struct button *restart;
} end_menu_t;

typedef struct setti_menu {
    int mapselect;
    sfSprite *background;
    slider_t *main_volume;
    slider_t *music;
    slider_t *effects;
    slider_t *ennemis;
    slider_t *alerts;
    slider_t *wind;
    struct trigger *vsync;
    struct trigger *focus;
    struct trigger *high_res;
    struct button *go_up;
    struct button *go_right;
    struct button *go_down;
    struct button *go_left;
    sfText *t_up;
    sfText *t_right;
    sfText *t_down;
    sfText *t_left;
    slider_t *luminosity;
    slider_t *contrast;
    slider_t *saturation;
    struct button *transp;
    struct button *transp2;
    struct button *graphic_b;
    struct button *binding_b;
    struct button *sounds_b;
    struct button *gui_b;
    struct button *menu_b;
    enum setting_step set_step;
} setti_menu_t;

typedef struct gen {
    keys_t keys;
    keymap_t *keymap;
    settings_t *saved;
    sfEvent event;
    sfView *camera;
    sfView *player;
    sound_t *sound;
    sfTexture *start;
    sfTexture *end;
    sfTexture *path;
    sfTexture *hitbox;
    sfTexture **textures;
    int texture_count;
    sfView *interface;
    sfRenderWindow *window;
    enum win_step game_step;
    sfClock *animation_clock;
    end_menu_t *end_menu;
    start_menu_t *start_menu;
    setti_menu_t *setti_menu;
    selec_menu_t *selec_menu;
    editor_menu_t *edit_menu;
    editor_eng_t *edit_engine;
    struct pause_menu *pause_menu;
    struct game *game_eng;
} gen_t;

struct pause_menu {
    sfSprite *calc;
    struct button *transp;
    struct button *resume_b;
    struct button *restart_b;
    struct button *settings_b;
    struct button *menu_b;
    struct button *exit_b;
};

typedef struct wave {
    int random;
    int count;
    int **meta;
} wave_t;

typedef struct wave_manager {
    wave_t *waves;
    int wave_count;
} wman_t;

typedef struct progress_bar {
    int value;
    sfVector2f coo;
    sfSprite *bar;
    sfSprite *frame;
    sfTexture *texture;
} progress_bar_t;

typedef struct game {
    pos_t last_mouse;
    sfSprite *cursor;
    sfText *cursor_info;
    int zoom;
    int trig;
    double life;
    double max_life;
    char *map_path;
    map_t *map;
    pos_t size;
    pos_t start;
    pos_t target;
    wman_t waves;
    ennemy_t *ennemies;
    enum in_game_state igs;
    int ennemies_count;
    int turret_id;
    int ennemy_id;
    int gear;
    int credit;
    sfText *gear_text;
    sfText *credit_text;
    sfSprite *transp_fric;
    sfSprite *gear_s;
    sfSprite *credit_s;
    turret_info_t turret_info;
    ennemy_t *ennemies_dic;
    int ennemies_dic_count;
    turrets_t *turrets;
    int turrets_count;
    turrets_t *turrets_dic;
    int turrets_dic_count;
    turrets_t *tmp_turret;
    sfSprite *silo;
    sfSprite *background;
    struct player *player;
    progress_bar_t health;
    progress_bar_t wave_progress;
    int turret_select;
    struct button *transp;
    struct button **turrets_btn;
} game_t;

struct player {
    sfSprite *player_sheet;
    sfVector2f coo;
    int skin_id;
    int idle;
    int dir;
};

struct button {
    sfText *text;
    sfVector2f coo;
    sfVector2f size;
    sfSprite *icon;
    sfSprite *sprite;
};

struct trigger {
    int state;
    sfText *text;
    sfVector2f coo;
    sfVector2f size;
    sfSprite *sprite;
    sfSprite *check;
};
/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** my_defender
*/

#include "structs.h"
#include "macros.h"

void window_update(gen_t *prm);
gen_t *get_struct_settings(void);
struct button *initialize_button(int px, int py, int sx, int sy);
void load_text_btn(struct button *button, int *trig, char *str);
slider_t *initialize_slider(int px, int py, int val, char *name);
struct trigger *initialize_trigger(int px, int py, char *text);
struct player *initialize_player(void);
keymap_t *load_key_mapping(void);

void manage_events(gen_t *prm);

//Maths
int random_gen(int min, int max);
float tange(double x);
float cosinus(double x);
float sinus(double x);
vec3_t get_vector3(int x, int y, int z);
pos_t get_vec2(int x, int y);
int *ennemy_find_in_sphere(game_t *game, pos_t or, int rad);

//Utils
int my_strlen(char *str);
int my_getnbr(char *str);
int my_str_find(char *c, char *arr);
int my_char_nbfind(char c, char *arr);
int my_str_isnum(char *str);
char **my_str_splitter(char *str, char sep);
char *str_truncate(char *str, int nbr);
char *str_add(char *str1, char *str2);
int my_strcmp(char *s1, char *s2);
int check_file(char *path);
char *my_strdup(char *src);

//My_get
sfSprite *get_sprite(char *path);
sfIntRect get_intrect(int top, int left, int width, int height);
sfVector2f get_vector(double x, double y);
int score_debugger(int nbr);
char *get_str(int val);

//My_window_create
sfRenderWindow *window_creator(void);

//My_click
int click_rel(sfEvent event, struct button *target);
int click_pre(sfEvent event, struct button *target);
int click_is_up(sfEvent event, struct button *target);
int tribush(sfEvent event, struct button * target);
int triforce(sfEvent event, struct button *target, sfSound *sound);
void slider_event(slider_t *slider, sfEvent event);
void trigger_event(struct trigger *trigger, sfEvent event);

//Map_loader
char *my_file_loader(char *path);
void sprite_texture(gen_t *gen, map_t *map, vec3_t pos, int tid);
pos_t get_location(map_t *map, char to_find);
void add_to_map(gen_t *gen, start_menu_t *menu, char *path, char *name);
pos_t get_map_size(char *path);
void get_maps(gen_t *gen, start_menu_t *menu);
void analyze_spmap_data(gen_t *gen, map_t *map, char **data);
void load_spmap(gen_t *gen, map_t *map);
map_t *get_map_by_path(start_menu_t *menu, char *path);
void sprite_property(gen_t *gen, map_t *map, vec3_t pos, int tid);

//texture/constructor.c
sfTexture *get_texture_by_id(gen_t *gen, int id);

//editor/map_block.c
void add_map_blocks(map_t *map, map_block_t block);
map_block_t *get_block_by_pos(map_t *map, vec3_t pos);
void save_blocks(map_t *map);
char *get_block(map_block_t b);
char *get_size(map_t *map);

//editor/paint.c
void paint_start(gen_t *prm, editor_eng_t *eng);
void paint_end(gen_t *prm, editor_eng_t *eng);
void paint_path(gen_t *prm, editor_eng_t *eng);
void default_paint(gen_t *prm, editor_eng_t *eng);
void paint_hitbox(editor_eng_t *eng);

//editor/map_gum.c
void delete_block_by_pos(map_t *map, vec3_t vec);
void gum(map_t *map, vec3_t vec);

//vmap_loader.c
void load_vmap(map_t *map);
void analyze_map_data(map_t *map, char **split);

//scenario/load.c
int load_scenario(gen_t *prm, char *file);
void load_waves(game_t *game, char *file);
void add_to_waves(game_t *game, char **settings);

//scenario/dir.c
void check_for_scenario(gen_t *gen, start_menu_t *menu, struct dirent *dir);
void get_scenarios(gen_t *gen, start_menu_t *menu);
void add_to_scena(gen_t *gen, start_menu_t *menu, char *path);

//scenario/scenario_validator.c
int scenario_is_valid(char *path);
int dictionnary_is_valid(char *data);
int dic_data_null(char **data);
int dic_data_valid(char **data);

//scenario/map_validator.c
int map_is_valid(char *path);
int map_data_valid(char **data);
int map_data_null(char **data);

//scenario/wave_validator.c
int wave_are_valid(char *data);
int wave_data_null(char **data);
int wave_data_valid(char **data);

//scenario/turret_validator.c
int turrets_are_valid(char *path);
int data_are_null(char **split);
int check_data_validity(char **data);

//scenario/utils.c
char *get_sname(char *path);
void sound_level(gen_t *prm);

//scenario/details.c
void get_scenario_detail(gen_t *gen, scenario_t *scen, char *path);
int get_wave_count(char **split);
void get_ennemy_dic(scen_detail_t *det, char *dic);
void add_to_scen_dico(scen_detail_t *det, char *split);

// ennemies/movements.c
int move_ennemy(game_t * game, ennemy_t *en);
pos_t get_next_move(pos_t pos);
pos_t get_rev_move(pos_t pos);

// ennemies/constructor.c
void create_ennemy(game_t *ge, int id);
int setup_ennemy_struct(game_t *ge, ennemy_t *new, int id);
void delete_ennemy_by_id(game_t *game, int id);
void set_ennemy_dictionnary(game_t *game, char *file);
void add_to_dico(game_t *game, char **settings);
ennemy_t *get_ennemy_by_id(game_t *game, int id);

// turrets/constructor.c
int create_turrets(game_t *game, int id, pos_t pos);
int load_turrets(game_t *game, char *data);
void add_to_turrets(game_t *game, char **data, int v);
int setup_turrets_struct(game_t *ge, turrets_t *new, int id, pos_t pos);

// turrets/events.c
int can_buy_turret(game_t *game, int id, pos_t pos);
void buy_turret(gen_t *gen, int id, pos_t pos);

// turrets/level.c
int can_upgrade_turret(game_t *game);
void upgrade_turret(game_t *game, int level);

// ennemies/wave_manager.c
int exec_wave(game_t *game);

// ennemies/spawner.c
void spawn_ennemies(gen_t *prm);

// ennemies/events.c
int ennemy_finded_goal(game_t *game, ennemy_t *en);
void check_ennemies_goal(game_t *game);

void map_printer(gen_t *prm);
void editor_map_printer(gen_t *prm);
void map_mini_printer(gen_t *prm, int i);
void map_mini_printer_bis(gen_t *prm, int i);
void load_map_textures(gen_t *prm, scen_detail_t *det);
void load_map_component(scen_detail_t *det);

void ennemies_animation(struct gen *prm);
void ennemies_printer(gen_t *prm);
void ennemies_mover(gen_t *prm);

void key_pressed(gen_t *prm);
void key_released(gen_t *prm);
int strokes_count(keys_t key);

void player_mover(gen_t *prm);
void player_animation(gen_t *prm);
int hit(gen_t *prm, int x, int y);

//drawer/draw_game1.c
void cursor_state(game_t *ge);
void draw_life_bar(gen_t *prm);
void draw_turrets_ui(game_t *eng, sfRenderWindow *window);

//drawer/draw_game2.C
void draw_back(gen_t *prm, game_t *ge, sfRenderWindow *win);
void draw_interface(gen_t *prm, game_t *eng, sfRenderWindow *win);

//Drawer stuff
void draw_slider(sfRenderWindow *window, struct slider *slider);
void draw_trigger(sfRenderWindow *window, struct trigger *trigger);
void draw_pause(gen_t *prm);
void draw_game(gen_t *prm);
void draw_start_menu(gen_t *prm);
void draw_game_settings(gen_t *prm);
void draw_settings(gen_t *prm);
void draw_selector(gen_t *prm);
void draw_editor_menu(gen_t *prm);
void draw_editor_eng(gen_t *prm);
void draw_end_menu(gen_t *prm);

void turrets_printer(gen_t *prm);
void turrets_angle(turrets_t *turrets, int angle);
void laser_handler(turrets_t *turrets, int angle, sfVector2f vec);
void setup_map_sprite(gen_t *prm, map_t *map, vec3_t pos);


keymap_t *load_key_mapping(void);
keys_t load_keys(void);

//Loading stuff
gen_t *get_struct_settings(void);
game_t *get_game_eng(void);
keymap_t *load_key_mapping(void);
keys_t load_keys(void);
sound_t *load_sounds(void);
start_menu_t *get_menu_s(void);
struct pause_menu *get_pause_s(void);
setti_menu_t *get_sett_s(void);
selec_menu_t *get_selector(gen_t *prm);
editor_menu_t *get_edit_s(gen_t *prm);
editor_eng_t *load_editor_eng(void);
end_menu_t *load_end_menu(void);
void update_keys(gen_t *prm, setti_menu_t *me, sfKeyCode key);
void load_text_settings_keymap_b(setti_menu_t *temp);
void load_text_settings_keymap_bis(setti_menu_t *temp);
void eng_bis(gen_t *prm);
int has_win(game_t *eng);
void turret_selector(gen_t *prm);
void informator_menu(gen_t *prm);
void turret_informator(gen_t *prm);


void mouse_move(gen_t *prm);
void editor_mouse_move(gen_t *prm);
void scroling(gen_t *prm);

void draw_settings_menu_text(gen_t *prm);
void draw_settings_menu(gen_t *prm);
void draw_settings(gen_t *prm);
void draw_settings_graph(gen_t *prm);
void draw_settings_keys(gen_t *prm);
void draw_settings_sounds(gen_t *prm);
void draw_settings_gui(gen_t *prm);

void game_eng_event(gen_t *prm);
void event_end_menu(gen_t *prm);
void pause_menu_event(gen_t *prm);
void settings_menu_event(gen_t *prm);
void start_menu_event(gen_t *prm);
void selec_menu_events(gen_t *prm);
void game_settings_menu_event(gen_t *prm);
void editor_menu_events(gen_t *prm);
void editor_eng_events(gen_t *prm, editor_eng_t *eng);
void set_pencil(gen_t *prm, editor_eng_t *eng);
void paint(gen_t *prm, editor_eng_t *eng);

int fire_ennemy(game_t *game, turrets_t *self, sound_t *sound);
int the_return_of_fire(turrets_t *self, sound_t *sound, sfVector2f v);
ennemy_t *get_ennemy_to_target(game_t *game, turrets_t *self);
int get_by_health(game_t *game, int *ids, int type);

turret_info_t setup_info_bubble(void);
void setup_info_bubble2(turret_info_t *info, sfFont *font);
void setup_info_bubble3(turret_info_t *info);
turrets_t *get_turret_by_pos(game_t *game, pos_t pos);
void delete_turret_by_id(game_t *game, int id);
turrets_t *get_turret_by_id(game_t *game, int id);
char *char_to_str(char c);

//free/game.c
void free_game(game_t *game);

void start_game(gen_t *prm);
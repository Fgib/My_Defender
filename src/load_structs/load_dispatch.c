/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** dispatch
*/

#include "my_defender.h"

void load_gen_textures(gen_t *prm)
{
    prm->path = sfTexture_createFromFile("assets/pics/concrete.png", NULL);
    prm->end = sfTexture_createFromFile("assets/pics/reac.png", NULL);
    prm->start = sfTexture_createFromFile("assets/pics/hive.png", NULL);
    prm->hitbox = sfTexture_createFromFile("assets/pics/barrier.png", NULL);

    prm->textures = malloc(sizeof(sfTexture *) * 6);
    prm->textures[0] = sfTexture_createFromFile("assets/pics/wall_sheet.png",
    NULL);
    prm->textures[1] = sfTexture_createFromFile("assets/pics/concrete.png",
    NULL);
    prm->textures[2] = sfTexture_createFromFile("assets/pics/water.png", NULL);
    prm->textures[3] = sfTexture_createFromFile("assets/trees/tree1.png", NULL);
    prm->textures[4] = sfTexture_createFromFile("assets/trees/tree2.png", NULL);
    prm->textures[5] = sfTexture_createFromFile("assets/trees/tree3.png", NULL);
}

gen_t *get_struct_settings(void)
{
    gen_t *prm = malloc(sizeof(gen_t));
    prm->animation_clock = sfClock_create();
    prm->sound = load_sounds();
    prm->pause_menu = get_pause_s();
    prm->window = window_creator();
    prm->start_menu = get_menu_s();
    prm->setti_menu = get_sett_s();
    prm->game_step = HOME;
    prm->keymap = load_key_mapping();
    prm->keys = load_keys();
    prm->texture_count = 6;
    prm->end_menu = load_end_menu();
    prm->about_menu = load_about_menu();

    prm->camera = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    prm->player = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    prm->interface = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    load_gen_textures(prm);
    write(1, "Everything loaded successfully\n\n", 32);
    return prm;
}
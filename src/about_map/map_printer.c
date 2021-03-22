/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** map_printer
*/

#include "my_defender.h"

void map_printer_loop(gen_t *prm, int x, int z)
{
    for (int y = 0; prm->game_eng->map->size.y > y; y++) {
        sfSprite_setScale(prm->game_eng->map->sp_map[x][y][z],
        get_vector(1, 1));
        sfSprite_setPosition(prm->game_eng->map->sp_map[x][y][z],
        get_vector(y * 30, x * 30));
        sfRenderWindow_drawSprite(prm->window,
        prm->game_eng->map->sp_map[x][y][z], NULL);
    }
}

void map_printer(gen_t *prm)
{
    for (int z = 0; z < 3; z++) {
        for (int x = 0; prm->game_eng->map->size.x > x; x++) {
            map_printer_loop(prm, x, z);
        }
    }
}

void editor_map_printer_loop(gen_t *prm, int x, int z)
{
    for (int y = 0; prm->edit_engine->map.size.y > y; y++) {
        sfSprite_setScale(prm->edit_engine->map.sp_map[x][y][z],
        get_vector(1, 1));
        sfSprite_setPosition(prm->edit_engine->map.sp_map[x][y][z],
        get_vector(y * 30, x * 30));
        sfRenderWindow_drawSprite(prm->window,
        prm->edit_engine->map.sp_map[x][y][z], NULL);
        if (prm->edit_engine->map.vmap[x][y] == '1' && z == 2) {
            sfSprite_setScale(prm->edit_engine->map.sp_map[x][y][3],
            get_vector(1, 1));
            sfSprite_setPosition(prm->edit_engine->map.sp_map[x][y][3],
            get_vector(y * 30, x * 30));
            sfRenderWindow_drawSprite(prm->window,
            prm->edit_engine->map.sp_map[x][y][3], NULL);
        }
    }
}

void editor_map_printer(gen_t *prm)
{
    for (int z = 0; z < 3; z++) {
        for (int x = 0; prm->edit_engine->map.size.x > x; x++) {
            editor_map_printer_loop(prm, x, z);
        }
    }
}


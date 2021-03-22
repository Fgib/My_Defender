/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** mini_map_printer
*/

#include "my_defender.h"

void map_mini_printer_loop(gen_t *prm, scenario_t *scen, pos_t v)
{
    for (int y = 0; y < scen->detail.map->size.y && y < 68; y++) {
        sfSprite_setPosition(scen->detail.map->sp_map[v.x][y][v.y],
        get_vector((y + 1) * 15 + 740 , (v.x + 1) * 15 + 320));
        sfSprite_setScale(scen->detail.map->sp_map[v.x][y][v.y],
        get_vector(0.5, 0.5));
        sfRenderWindow_drawSprite(prm->window,
        scen->detail.map->sp_map[v.x][y][v.y], NULL);
    }

}

void map_mini_printer(gen_t *prm, int i)
{
    for (int z = 0; z < 3; z++) {
        for (int x = 0; x < prm->start_menu->scenarios[i].detail.map->size.x &&
        x < 38; x++) {
            pos_t pos = get_vec2(x, z);
            map_mini_printer_loop(prm, &prm->start_menu->scenarios[i], pos);
        }
    }
}

void map_mini_printer_bis_loop(gen_t *prm, int i, int z, int x)
{
    for (int y = 0; y < prm->start_menu->maps[i].size.y && y < 68; y++) {
        sfSprite_setPosition(prm->start_menu->maps[i].sp_map[x][y][z],
        get_vector((y + 1) * 15 + 740 , (x + 1) * 15 + 320));
        sfSprite_setScale(prm->start_menu->maps[i].sp_map[x][y][z],
        get_vector(0.5, 0.5));
        sfRenderWindow_drawSprite(prm->window,
        prm->start_menu->maps[i].sp_map[x][y][z], NULL);
    }
}

void map_mini_printer_bis(gen_t *prm, int i)
{
    for (int z = 0; z < 3; z++) {
        for (int x = 0; x < prm->start_menu->maps[i].size.x && x < 38; x++) {
            map_mini_printer_bis_loop(prm, i, z, x);
        }
    }
}
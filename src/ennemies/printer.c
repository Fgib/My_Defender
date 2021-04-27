/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** ennemies_printer
*/

#include "my_defender.h"

void print_dead(gen_t *prm, int i)
{
    float size_ratio = prm->game_eng->ennemies[i].armor / 100.0;
    sfSprite_setPosition(prm->game_eng->ennemies[i].dead,
    get_vector(prm->game_eng->ennemies[i].pos.x * 30 +
    prm->game_eng->ennemies[i].pixel.x,
    prm->game_eng->ennemies[i].pos.y * 30 +
    prm->game_eng->ennemies[i].pixel.y));
    sfSprite_setScale(prm->game_eng->ennemies[i].dead,
    get_vector(size_ratio, size_ratio));
    sfRenderWindow_drawSprite(prm->window,
    prm->game_eng->ennemies[i].dead, NULL);
}

void print_alive(gen_t *prm, int i)
{
    sfSprite_setPosition(prm->game_eng->ennemies[i].skin,
    get_vector(prm->game_eng->ennemies[i].pos.x * 30 +
    prm->game_eng->ennemies[i].pixel.x + 15,
    prm->game_eng->ennemies[i].pos.y * 30 +
    prm->game_eng->ennemies[i].pixel.y + 15));
    sfRenderWindow_drawSprite(prm->window,
    prm->game_eng->ennemies[i].skin, NULL);
}

void ennemies_printer(gen_t *prm)
{
    for (int i = 0; i < prm->game_eng->ennemies_count; i++) {
        if (prm->game_eng->ennemies[i].health <= 0) {
            print_dead(prm, i);
        } else {
            print_alive(prm, i);
        }
    }
}
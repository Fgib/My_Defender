/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** ennemies_printer
*/

#include "my_defender.h"

void ennemies_printer(gen_t *prm)
{
    for (int i = 0; i < prm->game_eng->ennemies_count; i++) {
        if (prm->game_eng->ennemies[i].health <= 0) {
            sfSprite_setPosition(prm->game_eng->ennemies[i].dead,
            get_vector(prm->game_eng->ennemies[i].pos.x * 30 +
            prm->game_eng->ennemies[i].pixel.x,
            prm->game_eng->ennemies[i].pos.y * 30 +
            prm->game_eng->ennemies[i].pixel.y));
            sfRenderWindow_drawSprite(prm->window,
            prm->game_eng->ennemies[i].dead, NULL);
        } else {
            sfSprite_setPosition(prm->game_eng->ennemies[i].skin,
            get_vector(prm->game_eng->ennemies[i].pos.x * 30 +
            prm->game_eng->ennemies[i].pixel.x + 15,
            prm->game_eng->ennemies[i].pos.y * 30 +
            prm->game_eng->ennemies[i].pixel.y + 15));
            sfRenderWindow_drawSprite(prm->window,
            prm->game_eng->ennemies[i].skin, NULL);
        }
    }
}
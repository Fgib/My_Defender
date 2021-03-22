/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** spawner
*/

#include "my_defender.h"

void spawn_ennemies(gen_t *prm)
{
    int rate = 25;
    int random = random_gen(0, 1000);

    if (random <= rate && prm->game_eng->trig == 1) {
        exec_wave(prm->game_eng);
    }
}
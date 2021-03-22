/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** printer
*/

#include "my_defender.h"

void turrets_printer(gen_t *prm)
{
    for (int i = 0; i < prm->game_eng->turrets_count; i++) {
        sfSprite_setPosition(prm->game_eng->turrets[i].base,
        get_vector(prm->game_eng->turrets[i].pos.x * 30 - 15,
        prm->game_eng->turrets[i].pos.y * 30 - 15));
        sfSprite_setPosition(prm->game_eng->turrets[i].head,
        get_vector(prm->game_eng->turrets[i].pos.x * 30 - 15,
        prm->game_eng->turrets[i].pos.y * 30 - 50));
        sfRenderWindow_drawSprite(prm->window,
        prm->game_eng->turrets[i].base, NULL);
        sfRenderWindow_drawSprite(prm->window,
        prm->game_eng->turrets[i].head, NULL);
        sfRenderWindow_drawSprite(prm->window,
        prm->game_eng->turrets[i].projectile, NULL);
    }
}
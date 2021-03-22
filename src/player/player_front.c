/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** player
*/

#include "my_defender.h"

void player_animation(gen_t *prm)
{
    int h_offset;

    if (strokes_count(prm->keys) == 1) {
        h_offset = (prm->game_eng->player->dir - 1) * 136 + 544;
        sfSprite_setTextureRect(prm->game_eng->player->player_sheet,
        get_intrect(h_offset, prm->game_eng->player->skin_id * 108,
        108, 136));
        prm->game_eng->player->skin_id += prm->game_eng->player->skin_id <
        21 ? 1 : -21;
    } else {
        h_offset = (prm->game_eng->player->dir - 1) * 136;
        sfSprite_setTextureRect(prm->game_eng->player->player_sheet,
        get_intrect(h_offset, prm->game_eng->player->skin_id / 2 * 110,
        110, 136));
        prm->game_eng->player->skin_id += prm->game_eng->player->skin_id <
        42 ? 1 : -42;
    }
    sfClock_restart(prm->animation_clock);
}
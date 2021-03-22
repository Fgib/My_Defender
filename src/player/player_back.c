/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** player_back
*/

#include "my_defender.h"

int hit(gen_t *prm, int y, int x)
{
    pos_t pos;

    NVECTOR(pos, prm->game_eng->player->coo.y, prm->game_eng->player->coo.x);
    if ((pos.x + x) / 30 < 0 || (pos.x + x) / 30 >= prm->game_eng->map->size.x)
        return 0;
    if ((pos.y + y) / 30 < 0 || (pos.y + y) / 30 >= prm->game_eng->map->size.y)
        return 0;
    if (prm->game_eng->map->vmap[(pos.x + x) / 30][(pos.y + y) / 30] == '1')
        return 0;
    if (prm->game_eng->map->vmap[(pos.x + x) / 30][(pos.y + y) / 30] == '2')
        return 0;
    if (prm->game_eng->map->vmap[(pos.x + x) / 30][(pos.y + y) / 30] == '3')
        return 0;
    return 1;
}

void player_mover(gen_t *prm)
{
    if (prm->keys.mv_up && strokes_count(prm->keys) == 1 &&
    hit(prm, 0, -5)) {
        P_MOV(prm->game_eng->player->dir, 1, prm->game_eng->player->coo.y, -5);
    }
    if (prm->keys.mv_right && strokes_count(prm->keys) == 1 &&
    hit(prm, 5, 0)) {
        P_MOV(prm->game_eng->player->dir, 2, prm->game_eng->player->coo.x, +5);
    }
    if (prm->keys.mv_down && strokes_count(prm->keys) == 1 &&
    hit(prm, 0, +5)) {
        P_MOV(prm->game_eng->player->dir, 3, prm->game_eng->player->coo.y, +5);
    }
    if (prm->keys.mv_left && strokes_count(prm->keys) == 1 &&
    hit(prm, -5, 0)) {
        P_MOV(prm->game_eng->player->dir, 4, prm->game_eng->player->coo.x, -5);
    }
}
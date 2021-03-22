/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events
*/

#include "my_defender.h"

int can_buy_turret(game_t *game, int id, pos_t pos)
{
    turrets_t temp;
    pos_t coord;

    NVECTOR(coord, game->player->coo.x / 30, game->player->coo.y / 30)
    if (game->turrets_dic_count <= id)
        return 0;
    temp = game->turrets_dic[id];
    for (int i = 0; i < game->turrets_count; ++i)
        if (RVECTOR(game->turrets[i].pos, pos, 1))
            return -1;
    if (!RVECTOR(coord, pos, 6))
        return -3;
    if (game->credit < temp.price)
        return -2;
    return 1;
}

void buy_turret(gen_t *gen, int id, pos_t pos)
{
    turrets_t temp;

    if (can_buy_turret(gen->game_eng, id, pos) <= 0) {
        sfSound_play(gen->sound->impossible);
        return;
    }
    temp = gen->game_eng->turrets_dic[id];
    create_turrets(gen->game_eng, id, pos);
    gen->game_eng->credit -= temp.price;
    gen->game_eng->turret_select = -1;
}
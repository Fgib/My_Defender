/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** movements
*/

#include "my_defender.h"

void ennemy_place(ennemy_t *en)
{
    if (en->pixel.x > 29) {
        en->pos.x++;
        en->pixel.x = 0;
    }
    if (en->pixel.y > 29) {
        en->pos.y++;
        en->pixel.y = 0;
    }
    if (en->pixel.x < -29) {
        en->pos.x--;
        en->pixel.x = 0;
    }
    if (en->pixel.y < -29) {
        en->pos.y--;
        en->pixel.y = 0;
    }
}

int move_ennemy(game_t *game, ennemy_t *en)
{
    pos_t move = en->last_dir;
    pos_t rpos = get_rev_move(en->last_dir);
    int i;

    for (i = 0; i < 4; ++i) {
        if (game->map->vmap[en->pos.y + move.y][en->pos.x + move.x]
            == '4' && !CVECTOR(move, rpos))
            break;
        move = get_next_move(move);
    }
    if (i == 4)
        return 0;
    AVECTOR(en->pixel, move.x * en->speed, move.y * en->speed);
    ennemy_place(en);
    en->last_dir = move;
    return 1;
}

void ennemies_mover(gen_t *prm)
{
    for (int i = 0; i < prm->game_eng->ennemies_count; i++)
        if (prm->game_eng->ennemies[i].health > 0)
            move_ennemy(prm->game_eng, &prm->game_eng->ennemies[i]);
}

pos_t get_next_move(pos_t pos)
{
    pos_t npos;
    npos.x = 0;
    npos.y = 0;

    npos.y = (pos.x == 1) ? 1 : (pos.x == -1) ? -1 : 0;
    npos.x = (pos.y == 1) ? -1 : (pos.y == -1) ? 1 : 0;
    return npos;
}

pos_t get_rev_move(pos_t pos)
{
    pos_t npos;
    npos.x = 0;
    npos.y = 0;

    npos.x = (pos.x == 1) ? -1 : (pos.x == -1) ? 1 : 0;
    npos.y = (pos.y == 1) ? -1 : (pos.y == -1) ? 1 : 0;
    return npos;
}
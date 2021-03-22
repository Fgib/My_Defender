/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** levels
*/

#include "my_defender.h"

int can_upgrade_turret(game_t *game)
{
    if (!game->tmp_turret)
        return 0;
    if (game->tmp_turret->level > 3)
        return -1;
    if (game->gear < pow(5, game->tmp_turret->level))
        return -1;
    return 1;
}

void upgrade_turret(game_t *game, int level)
{
    for (int i = 0; i < level; i++) {
        if (game->tmp_turret->level >= 3)
            return;
        game->tmp_turret->damage *= 1.5;
        game->tmp_turret->range += 1;
        game->tmp_turret->fire_rate -= 1;
        if (game->tmp_turret->fire_rate <= 0)
            game->tmp_turret->fire_rate = 1;
        game->gear -= pow(5, game->tmp_turret->level);
        game->tmp_turret->level++;
    }
}
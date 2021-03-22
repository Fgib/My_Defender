/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** game
*/

#include "my_defender.h"

void free_game(game_t *game)
{
    if (game->ennemies_count)
        free(game->ennemies);
    game->ennemies_count = 0;
    game->ennemy_id = 0;

    if (game->turrets_count)
        free(game->turrets);
    game->turrets_count = 0;
    game->turret_id = 0;
    free(game);
}
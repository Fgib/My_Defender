/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** wave_manager
*/

#include "my_defender.h"

int get_wave_ennemy(game_t *ge, int i)
{
    int w = 0;

    if (ge->waves.waves[i].random) {
        do
        w = random_gen(0, ge->waves.waves[i].count - 1);
        while (!ge->waves.waves[i].meta[w][1]);
    } else
        for (w = 0; ge->waves.waves[i].meta[w][1] == 0; w++);
    return w;
}

int exec_wave(game_t *game)
{
    int i;
    int w;

    for (i = 0; i < game->waves.wave_count; i++)
        if (game->waves.waves[i].random != -1)
            break;
    if (i == game->waves.wave_count)
        return 0;
    w = get_wave_ennemy(game, i);
    create_ennemy(game, w);
    game->waves.waves[i].meta[w][1]--;
    for (w = 0; w < game->waves.waves[i].count; w++)
        if (game->waves.waves[i].meta[w][1] != 0)
            break;
    (w == game->waves.waves[i].count) ? game->waves.waves[i].random = -1 : 0;
    if (game->waves.waves[i].random == -1)
        return -1;
    return 1;
}
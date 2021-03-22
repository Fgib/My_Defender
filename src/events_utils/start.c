/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** start
*/

#include "my_defender.h"

void start_game(gen_t *prm)
{
    int temp;

    prm->game_eng = get_game_eng();
    temp = load_scenario(prm, prm->start_menu->scenarios[
    prm->selec_menu->select].path);
    if (!temp)
        return;
    prm->game_eng->start = get_location(prm->game_eng->map, '2');
    prm->game_eng->target = get_location(prm->game_eng->map, '3');
    sfMusic_play(prm->sound->wind);
    prm->game_step = GAME;
}
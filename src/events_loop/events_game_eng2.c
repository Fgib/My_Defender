/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** event_game_eng2
*/

#include "my_defender.h"

void eng_bis(gen_t *prm)
{
    mouse_move(prm);
    scroling(prm);
    turret_informator(prm);
    if (prm->game_eng->igs == INFORM) {
        informator_menu(prm);
    }
    if (prm->game_eng->life <= 0)
        prm->game_step = GAME_OVER;
    else if (has_win(prm->game_eng))
        prm->game_step = GAME_WIN;
    turret_selector(prm);
}
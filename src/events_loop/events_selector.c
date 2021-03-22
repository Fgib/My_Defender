/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events_selector
*/

#include "my_defender.h"

void selec_menu_launch(gen_t *prm)
{
    if (triforce(prm->event, prm->selec_menu->play, prm->sound->btn_press)
        && prm->selec_menu->select >= 0)
        start_game(prm);
}

void selec_menu_events(gen_t *prm)
{

    if (triforce(prm->event, prm->selec_menu->home, prm->sound->btn_press))
        prm->game_step = HOME;
    for (int i = 0; i < prm->start_menu->scenario_count; i++) {
        if (triforce(prm->event, prm->selec_menu->scenarios_btn[i],
            prm->sound->btn_press))
            prm->selec_menu->select = i;
    }
    selec_menu_launch(prm);
}
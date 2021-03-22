/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events_end_menu
*/

#include "my_defender.h"

void event_end_menu(gen_t *prm)
{
    if (triforce(prm->event, prm->end_menu->home, prm->sound->btn_press))
        prm->game_step = HOME;
    if (triforce(prm->event, prm->end_menu->home, prm->sound->btn_press)) {
        start_game(prm);
        prm->game_step = GAME;
    }
}
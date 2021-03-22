/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events_pause_menu
*/

#include "my_defender.h"

void pause_menu_restart(gen_t *prm)
{
    if (triforce(prm->event, prm->pause_menu->restart_b,
    prm->sound->btn_press)) {
        start_game(prm);
    }
}

void pause_menu_event(gen_t *prm)
{

    if (triforce(prm->event, prm->pause_menu->resume_b,
    prm->sound->btn_press)) {
        prm->game_step = GAME;
    }
    pause_menu_restart(prm);
    if (triforce(prm->event, prm->pause_menu->settings_b,
        prm->sound->btn_press))
        prm->game_step = G_SETTINGS;
    if (triforce(prm->event, prm->pause_menu->menu_b,
    prm->sound->btn_press)) {
        prm->game_step = HOME;
    }
    if (triforce(prm->event, prm->pause_menu->exit_b,
    prm->sound->btn_press)) {
        prm->game_step = OUT;
    }
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events_start_menu
*/

#include "my_defender.h"

void start_menu_event(gen_t *prm)
{
    if (triforce(prm->event, prm->start_menu->sett_b, prm->sound->btn_press))
        prm->game_step = SETTINGS;
    if (triforce(prm->event, prm->start_menu->exit_b, prm->sound->btn_press) ||
        prm->event.key.code == sfKeyEscape)
        prm->game_step = OUT;
    if (triforce(prm->event, prm->start_menu->abot_b, prm->sound->btn_press))
        write(1, "About\n", 6);
    if (triforce(prm->event, prm->start_menu->edit_b, prm->sound->btn_press)) {
        get_maps(prm, prm->start_menu);
        prm->edit_menu = get_edit_s(prm);
        prm->game_step = EDITOR_MENU;
    }
    if (triforce(prm->event, prm->start_menu->play_b, prm->sound->btn_press)) {
        get_maps(prm, prm->start_menu);
        get_scenarios(prm, prm->start_menu);
        prm->selec_menu = get_selector(prm);
        prm->game_step = SELECTOR;
    }
}

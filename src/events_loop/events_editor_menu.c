/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** evetnts_editor_menu
*/

#include "my_defender.h"

void editor_menu_events(gen_t *prm)
{
    if (triforce(prm->event, prm->edit_menu->home, prm->sound->btn_press))
        prm->game_step = HOME;
    for (int i = 0; i < prm->start_menu->map_count; i++) {
        if (triforce(prm->event, prm->edit_menu->maps_btn[i],
            prm->sound->btn_press))
            prm->edit_menu->select = i;
    }
    if (triforce(prm->event, prm->edit_menu->build, prm->sound->btn_press)) {
        prm->game_step = EDITOR_ENGINE;
        prm->edit_engine = load_editor_eng();
        prm->edit_engine->map = prm->start_menu->maps[prm->edit_menu->select];
    }
}
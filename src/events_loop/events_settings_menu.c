/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events_settings_menu
*/

#include "my_defender.h"

void events_sub_settings_graph(gen_t *prm)
{
    if (prm->setti_menu->set_step == SET_GRAPH) {
        trigger_event(prm->setti_menu->vsync, prm->event);
        trigger_event(prm->setti_menu->focus, prm->event);
        trigger_event(prm->setti_menu->high_res, prm->event);
        if (prm->keys.mouse) {
            slider_event(prm->setti_menu->luminosity, prm->event);
            slider_event(prm->setti_menu->contrast, prm->event);
            slider_event(prm->setti_menu->saturation, prm->event);
        }
    }
}

void events_sub_settings_sound(gen_t *prm)
{
    if (prm->keys.mouse && prm->setti_menu->set_step == SET_SOUND) {
        slider_event(prm->setti_menu->main_volume, prm->event);
        slider_event(prm->setti_menu->music, prm->event);
        slider_event(prm->setti_menu->effects, prm->event);
        slider_event(prm->setti_menu->ennemis, prm->event);
        slider_event(prm->setti_menu->alerts, prm->event);
        slider_event(prm->setti_menu->wind, prm->event);
    }
}

void events_sub_settings_keys(gen_t *prm)
{
    if (prm->setti_menu->set_step == SET_KEYS) {
        if (triforce(prm->event, prm->setti_menu->go_up,
            prm->sound->btn_press))
            prm->setti_menu->mapselect = 1;
        if (triforce(prm->event, prm->setti_menu->go_right,
            prm->sound->btn_press))
            prm->setti_menu->mapselect = 2;
        if (triforce(prm->event, prm->setti_menu->go_down,
            prm->sound->btn_press))
            prm->setti_menu->mapselect = 3;
        if (triforce(prm->event, prm->setti_menu->go_left,
            prm->sound->btn_press))
            prm->setti_menu->mapselect = 4;
        if (prm->event.type == sfEvtKeyPressed && prm->setti_menu->mapselect)
            update_keys(prm, prm->setti_menu, prm->event.key.code);
    }
}

void settings_menu_event(gen_t *prm)
{
    if (triforce(prm->event, prm->setti_menu->graphic_b, prm->sound->btn_press))
        prm->setti_menu->set_step = SET_GRAPH;
    if (triforce(prm->event, prm->setti_menu->binding_b, prm->sound->btn_press))
        prm->setti_menu->set_step = SET_KEYS;
    if (triforce(prm->event, prm->setti_menu->sounds_b, prm->sound->btn_press))
        prm->setti_menu->set_step = SET_SOUND;
    if (triforce(prm->event, prm->setti_menu->gui_b, prm->sound->btn_press))
        prm->setti_menu->set_step = SET_GUI;
    if (triforce(prm->event, prm->setti_menu->menu_b, prm->sound->btn_press)) {
        prm->setti_menu->set_step = SET_HOME;
        prm->game_step = HOME;
    }
    events_sub_settings_graph(prm);
    events_sub_settings_sound(prm);
    events_sub_settings_keys(prm);
}

void game_settings_menu_event(gen_t *prm)
{
    if (triforce(prm->event, prm->setti_menu->graphic_b, prm->sound->btn_press))
        prm->setti_menu->set_step = SET_GRAPH;
    if (triforce(prm->event, prm->setti_menu->binding_b, prm->sound->btn_press))
        prm->setti_menu->set_step = SET_KEYS;
    if (triforce(prm->event, prm->setti_menu->sounds_b, prm->sound->btn_press))
        prm->setti_menu->set_step = SET_SOUND;
    if (triforce(prm->event, prm->setti_menu->gui_b, prm->sound->btn_press))
        prm->setti_menu->set_step = SET_GUI;
    if (triforce(prm->event, prm->setti_menu->menu_b, prm->sound->btn_press)) {
        prm->setti_menu->set_step = SET_HOME;
        prm->game_step = PAUSE;
    }
    events_sub_settings_graph(prm);
    events_sub_settings_sound(prm);
    events_sub_settings_keys(prm);
}
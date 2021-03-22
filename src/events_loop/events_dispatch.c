/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events_dispatch
*/

#include "my_defender.h"

void manage_event2(gen_t *prm)
{
    if (prm->game_step == GAME)
        game_eng_event(prm);
    if (prm->game_step == PAUSE)
        pause_menu_event(prm);
    if (prm->game_step == G_SETTINGS)
        game_settings_menu_event(prm);
    if (prm->game_step == GAME_WIN || prm->game_step == GAME_OVER)
        event_end_menu(prm);
}

void manage_events(gen_t *prm)
{
    key_pressed(prm);
    key_released(prm);
    if (prm->event.type == sfEvtClosed)
        sfRenderWindow_close(prm->window);
    if (prm->game_step == HOME)
        start_menu_event(prm);
    if (prm->game_step == SELECTOR)
        selec_menu_events(prm);
    if (prm->game_step == EDITOR_MENU)
        editor_menu_events(prm);
    if (prm->game_step == EDITOR_ENGINE)
        editor_eng_events(prm, prm->edit_engine);
    if (prm->game_step == SETTINGS)
        settings_menu_event(prm);
    manage_event2(prm);
}
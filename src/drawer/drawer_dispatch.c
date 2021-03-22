/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** draw_window
*/

#include "my_defender.h"

void window_update(gen_t *prm)
{
    if (prm->game_step == HOME)
        draw_start_menu(prm);
    if (prm->game_step == SETTINGS)
        draw_settings(prm);
    if (prm->game_step == EDITOR_MENU)
        draw_editor_menu(prm);
    if (prm->game_step == EDITOR_ENGINE)
        draw_editor_eng(prm);
    if (prm->game_step == SELECTOR)
        draw_selector(prm);
    if (prm->game_step == GAME || prm->game_step == PAUSE ||
        prm->game_step == G_SETTINGS)
        draw_game(prm);
    if (prm->game_step == G_SETTINGS)
        draw_game_settings(prm);
    if (prm->game_step == PAUSE)
        draw_pause(prm);
    if (prm->game_step == GAME_OVER || prm->game_step == GAME_WIN)
        draw_end_menu(prm);
}
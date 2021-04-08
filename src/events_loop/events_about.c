/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events_about
*/

#include "my_defender.h"

void event_about_menu(gen_t *prm)
{
    if (triforce(prm->event, prm->about_menu->exit, prm->sound->btn_press))
        prm->game_step = HOME;
}
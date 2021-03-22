/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** mouse
*/

#include "my_defender.h"

void mouse_move(gen_t *prm)
{
    if (prm->event.type == sfEvtMouseMoved) {
        NVECTOR(prm->game_eng->last_mouse, (prm->event.mouseMove.x - 960)
        / 30 * powf(0.95, prm->game_eng->zoom) +
        prm->game_eng->player->coo.x /30,
        (prm->event.mouseMove.y - 540) / 30 *
        powf(0.95, prm->game_eng->zoom) +
        prm->game_eng->player->coo.y / 30);
    }
}

void editor_mouse_move(gen_t *prm)
{
    if (prm->event.type == sfEvtMouseMoved) {
        NVECTOR(prm->edit_engine->last_mouse, prm->event.mouseMove.x / 30,
        prm->event.mouseMove.y / 30);
    }
}
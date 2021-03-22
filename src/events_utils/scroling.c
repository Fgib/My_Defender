/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** scroling
*/

#include "my_defender.h"

void scroling(gen_t *prm)
{
    if (prm->event.type == sfEvtMouseWheelScrolled) {
        if (prm->event.mouseWheelScroll.delta > 0 &&
        prm->game_eng->zoom <= 40) {
            sfView_zoom(prm->camera, 0.95);
            sfView_zoom(prm->player, 0.95);
            prm->game_eng->zoom += 1;
        }
        if (prm->event.mouseWheelScroll.delta < 0 && prm->game_eng->zoom > 0) {
            sfView_zoom(prm->camera, 1.05);
            sfView_zoom(prm->player, 1.05);
            prm->game_eng->zoom -= 1;
        }
    }
}


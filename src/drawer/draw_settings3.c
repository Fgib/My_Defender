/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_settings3
*/

#include "my_defender.h"

void draw_settings_sounds(gen_t *prm)
{
    sfText_setString(prm->setti_menu->transp2->text, "Sounds Settings");
    sfRenderWindow_drawText(prm->window, prm->setti_menu->transp2->text, NULL);

    draw_slider(prm->window, prm->setti_menu->main_volume);
    draw_slider(prm->window, prm->setti_menu->music);
    draw_slider(prm->window, prm->setti_menu->effects);
    draw_slider(prm->window, prm->setti_menu->ennemis);
    draw_slider(prm->window, prm->setti_menu->alerts);
    draw_slider(prm->window, prm->setti_menu->wind);
}

void draw_settings_gui(gen_t *prm)
{
    sfText_setString(prm->setti_menu->transp2->text, "Interface Settings");
    sfRenderWindow_drawText(prm->window, prm->setti_menu->transp2->text, NULL);
}
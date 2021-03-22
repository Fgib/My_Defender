/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_settings2
*/

#include "my_defender.h"

void draw_settings_graph(gen_t *prm)
{
    sfText_setString(prm->setti_menu->transp2->text, "Graphics Settings");
    sfRenderWindow_drawText(prm->window, prm->setti_menu->transp2->text, NULL);

    draw_trigger(prm->window, prm->setti_menu->vsync);
    draw_trigger(prm->window, prm->setti_menu->focus);
    draw_trigger(prm->window, prm->setti_menu->high_res);
    draw_slider(prm->window, prm->setti_menu->luminosity);
    draw_slider(prm->window, prm->setti_menu->contrast);
    draw_slider(prm->window, prm->setti_menu->saturation);
}

void draw_settings_keys_bis(gen_t *prm)
{
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->t_up, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->t_right, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->t_down, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->t_left, NULL);
}

void draw_settings_keys(gen_t *prm)
{
    sfText_setString(prm->setti_menu->transp2->text, "Keyboard Settings");
    sfRenderWindow_drawText(prm->window, prm->setti_menu->transp2->text, NULL);

    sfRenderWindow_drawSprite(prm->window,
    prm->setti_menu->go_up->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->setti_menu->go_right->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->setti_menu->go_down->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->setti_menu->go_left->sprite, NULL);

    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->go_up->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->go_right->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->go_down->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->go_left->text, NULL);
}


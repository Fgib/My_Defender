/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_settings
*/

#include "my_defender.h"

void draw_settings_menu_text(gen_t *prm)
{
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->transp->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->graphic_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->binding_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->sounds_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->gui_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->setti_menu->menu_b->text, NULL);
}

void draw_settings_menu(gen_t *prm)
{
    sfRenderWindow_drawSprite(prm->window,
    prm->setti_menu->transp->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->setti_menu->graphic_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->setti_menu->binding_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->setti_menu->sounds_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->setti_menu->gui_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->setti_menu->menu_b->sprite, NULL);
    draw_settings_menu_text(prm);
}

void draw_settings(gen_t *prm)
{
    sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
    sfRenderWindow_drawSprite(prm->window, prm->setti_menu->background, NULL);
    draw_settings_menu(prm);
    if (prm->setti_menu->set_step != SET_HOME)
        sfRenderWindow_drawSprite(prm->window, prm->setti_menu->transp2->sprite,
        NULL);
    if (prm->setti_menu->set_step == SET_GRAPH)
        draw_settings_graph(prm);
    if (prm->setti_menu->set_step == SET_KEYS)
        draw_settings_keys(prm);
    if (prm->setti_menu->set_step == SET_SOUND)
        draw_settings_sounds(prm);
    if (prm->setti_menu->set_step == SET_GUI)
        draw_settings_gui(prm);
}

void draw_game_settings(gen_t *prm)
{
    sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
    sfRenderWindow_drawSprite(prm->window, prm->pause_menu->calc, NULL);
    draw_settings_menu(prm);
    if (prm->setti_menu->set_step != SET_HOME)
        sfRenderWindow_drawSprite(prm->window, prm->setti_menu->transp2->sprite,
        NULL);
    if (prm->setti_menu->set_step == SET_GRAPH)
        draw_settings_graph(prm);
    if (prm->setti_menu->set_step == SET_KEYS)
        draw_settings_keys(prm);
    if (prm->setti_menu->set_step == SET_SOUND)
        draw_settings_sounds(prm);
    if (prm->setti_menu->set_step == SET_GUI)
        draw_settings_gui(prm);
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_pause
*/

#include "my_defender.h"


void draw_pause_text(gen_t *prm)
{
    sfRenderWindow_drawText(prm->window,
    prm->pause_menu->transp->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->pause_menu->resume_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->pause_menu->restart_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->pause_menu->settings_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->pause_menu->menu_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->pause_menu->exit_b->text, NULL);
}

void draw_pause(gen_t *prm)
{
    sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
    sfRenderWindow_drawSprite(prm->window, prm->pause_menu->calc, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->pause_menu->transp->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->pause_menu->resume_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->pause_menu->restart_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->pause_menu->settings_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->pause_menu->menu_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->pause_menu->exit_b->sprite, NULL);
    draw_pause_text(prm);
}
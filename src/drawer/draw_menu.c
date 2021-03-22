/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_menu
*/

#include "my_defender.h"

void draw_start_menu_text(gen_t *prm)
{
    sfRenderWindow_drawText(prm->window,
    prm->start_menu->transp->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->start_menu->play_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->start_menu->edit_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->start_menu->sett_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->start_menu->abot_b->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->start_menu->exit_b->text, NULL);
}

void draw_start_menu(gen_t *prm)
{
    sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);

    sfRenderWindow_drawSprite(prm->window,
    prm->start_menu->background, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->start_menu->transp->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->start_menu->play_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->start_menu->edit_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->start_menu->sett_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->start_menu->abot_b->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->start_menu->exit_b->sprite, NULL);
    draw_start_menu_text(prm);
}
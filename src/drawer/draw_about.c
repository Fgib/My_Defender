/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_about
*/

#include "my_defender.h"

void draw_about_menu(gen_t *prm)
{
    sfRenderWindow_drawSprite(prm->window,
    prm->about_menu->background, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->about_menu->transp->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->about_menu->exit->sprite, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->about_menu->transp->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->about_menu->exit->text, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->about_menu->text, NULL);
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_end_menu
*/

#include "my_defender.h"

void draw_end_menu(gen_t *prm)
{
    sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);

    sfRenderWindow_drawSprite(prm->window, prm->end_menu->background, NULL);
    sfRenderWindow_drawSprite(prm->window, prm->end_menu->transp->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window, prm->end_menu->home->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->end_menu->home->text, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->end_menu->restart->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->end_menu->restart->text, NULL);
    if (prm->game_step == GAME_OVER) {
        sfText_setPosition(prm->end_menu->condition, get_vector(700, 400));
        sfText_setString(prm->end_menu->condition, "You Loose !");
    }
    if (prm->game_step == GAME_WIN) {

        sfText_setPosition(prm->end_menu->condition, get_vector(750, 400));
        sfText_setString(prm->end_menu->condition, "You Won !");
    }
    sfRenderWindow_drawText(prm->window, prm->end_menu->condition, NULL);
}
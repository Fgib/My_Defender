/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_editor_menu
*/

#include "my_defender.h"

void draw_editor_menu_list(gen_t *prm)
{
    for (int i = 0; i < prm->start_menu->map_count; i++) {
        sfRenderWindow_drawSprite(prm->window,
        prm->edit_menu->maps_btn[i]->sprite, NULL);
        sfRenderWindow_drawText(prm->window,
        prm->edit_menu->maps_btn[i]->text, NULL);
    }
    if (prm->edit_menu->select != -1) {
        sfRenderWindow_drawSprite(prm->window,
        prm->edit_menu->transp2->sprite, NULL);
        sfRenderWindow_drawText(prm->window,
        prm->edit_menu->transp2->text, NULL);
        sfRenderWindow_drawSprite(prm->window,
        prm->edit_menu->build->sprite, NULL);
        sfRenderWindow_drawText(prm->window,
        prm->edit_menu->build->text, NULL);
        map_mini_printer_bis(prm, prm->edit_menu->select);
    }
}

void draw_editor_menu(gen_t *prm)
{
    sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
    sfRenderWindow_drawSprite(prm->window, prm->edit_menu->background, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_menu->transp1->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window, prm->edit_menu->home->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->edit_menu->transp1->text, NULL);
    sfRenderWindow_drawText(prm->window, prm->edit_menu->home->text, NULL);

    draw_editor_menu_list(prm);
}
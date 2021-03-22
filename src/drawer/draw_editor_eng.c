/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_editor_eng
*/

#include "my_defender.h"

void draw_editor_btns1(gen_t *prm)
{
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->path->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->path->icon, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->water->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->water->icon, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->start->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->start->icon, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->end->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->end->icon, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->erase->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->erase->icon, NULL);
}

void draw_editor_btns2(gen_t *prm)
{
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->layer_up->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->layer_up->icon, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->layer_down->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->layer_down->icon, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->hitbox->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->hitbox->icon, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->tree1->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->tree1->icon, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->tree2->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->tree2->icon, NULL);
}

void draw_editor_btns3(gen_t *prm)
{
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->tree3->sprite, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->tree3->icon, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->edit_engine->useless->sprite, NULL);
}

void draw_editor_eng(gen_t *prm)
{
    editor_mouse_move(prm);
    sfRenderWindow_drawSprite(prm->window, prm->edit_engine->background, NULL);
    editor_map_printer(prm);
    draw_editor_btns1(prm);
    draw_editor_btns2(prm);
    draw_editor_btns3(prm);
    sfSprite_setPosition(prm->edit_engine->cursor,
    get_vector(prm->edit_engine->last_mouse.x * 30,
    prm->edit_engine->last_mouse.y * 30));
    sfRenderWindow_drawSprite(prm->window, prm->edit_engine->cursor, NULL);
    sfText_setString(prm->edit_engine->layer_t,
    get_str(prm->edit_engine->layer + 1));
    sfRenderWindow_drawText(prm->window, prm->edit_engine->layer_t, NULL);
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events_editor_eng
*/

#include "my_defender.h"

void editor_eng_events(gen_t *prm, editor_eng_t *eng)
{
    if (prm->event.type == sfEvtKeyPressed &&
    prm->event.key.code == sfKeyEscape && eng->select == 0) {
        save_blocks(&eng->map);
        prm->game_step = EDITOR_MENU;
    }
    if (prm->event.type == sfEvtKeyPressed &&
        prm->event.key.code == sfKeyEscape && eng->select != 0)
        eng->select = 0;
    if (prm->keys.mouse && eng->select != 0)
        if (eng->last_mouse.x < eng->map.size.y && eng->last_mouse.x > 0 &&
            eng->last_mouse.y > 0 && eng->last_mouse.y < eng->map.size.x)
            paint(prm, prm->edit_engine);
    if (triforce(prm->event, eng->layer_up, prm->sound->btn_press))
        eng->layer += eng->layer < 2 ? 1 : 0;
    if (triforce(prm->event, eng->layer_down, prm->sound->btn_press))
        eng->layer -= eng->layer > 0 ? 1 : 0;
    set_pencil(prm, prm->edit_engine);
}

void set_pencil(gen_t *prm, editor_eng_t *eng)
{
    if (triforce(prm->event, eng->water, prm->sound->btn_press))
        prm->edit_engine->select = 3;
    if (triforce(prm->event, eng->tree1, prm->sound->btn_press))
        prm->edit_engine->select = 4;
    if (triforce(prm->event, eng->tree2, prm->sound->btn_press))
        prm->edit_engine->select = 5;
    if (triforce(prm->event, eng->tree3, prm->sound->btn_press))
        prm->edit_engine->select = 6;
    if (triforce(prm->event, eng->erase, prm->sound->btn_press))
        prm->edit_engine->select = -1;
    if (triforce(prm->event, eng->start, prm->sound->btn_press))
        prm->edit_engine->select = -2;
    if (triforce(prm->event, eng->end, prm->sound->btn_press))
        prm->edit_engine->select = -3;
    if (triforce(prm->event, eng->path, prm->sound->btn_press))
        prm->edit_engine->select = -4;
    if (triforce(prm->event, eng->hitbox, prm->sound->btn_press))
        prm->edit_engine->select = -5;
}

void paint(gen_t *prm, editor_eng_t *eng)
{
    if (eng->select == -1)
        gum(&eng->map,
        get_vector3(eng->last_mouse.y, eng->last_mouse.x, eng->layer));
    if (eng->select == -2)
        paint_start(prm, eng);
    if (eng->select == -3)
        paint_end(prm, eng);
    if (eng->select == -4)
        paint_path(prm, eng);
    if (eng->select == -5)
        paint_hitbox(eng);
    if (eng->select > 0)
        default_paint(prm, eng);
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** key_strokes
*/

#include "my_defender.h"

void key_pressed(gen_t *prm)
{
    if (prm->event.type == sfEvtMouseButtonPressed)
        prm->keys.mouse = 1;
    if (prm->event.type == sfEvtKeyPressed) {
        if (prm->event.key.code == prm->keymap->w)
            prm->keys.mv_up = 1;
        if (prm->event.key.code == prm->keymap->a)
            prm->keys.mv_left = 1;
        if (prm->event.key.code == prm->keymap->s)
            prm->keys.mv_down = 1;
        if (prm->event.key.code == prm->keymap->d)
            prm->keys.mv_right = 1;
        if (prm->event.key.code == sfKeySpace)
            prm->keys.space = 1;
        if (prm->event.key.code == sfKeyTab)
            prm->keys.tab = 1;
    }
}

void key_released(gen_t *prm)
{
    if (prm->event.type == sfEvtMouseButtonReleased)
        prm->keys.mouse = 0;
    if (prm->event.type == sfEvtKeyReleased) {
        if (prm->event.key.code == prm->keymap->w)
            prm->keys.mv_up = 0;
        if (prm->event.key.code == prm->keymap->a)
            prm->keys.mv_left = 0;
        if (prm->event.key.code == prm->keymap->s)
            prm->keys.mv_down = 0;
        if (prm->event.key.code == prm->keymap->d)
            prm->keys.mv_right = 0;
        if (prm->event.key.code == sfKeySpace)
            prm->keys.space = 0;
        if (prm->event.key.code == sfKeyTab)
            prm->keys.tab = 0;
    }
}

int strokes_count(keys_t key)
{
    int result = key.mv_down + key.mv_left + key.mv_right + key.mv_up;
    if (result > 1)
        return 2;
    else if (result == 1)
        return 1;
    else
        return 0;
}
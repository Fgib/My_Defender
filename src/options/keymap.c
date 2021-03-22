/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** keymap
*/

#include "my_defender.h"

void update_keys(gen_t *prm, setti_menu_t *me, sfKeyCode key)
{
    if (me->mapselect) {
        if (me->mapselect == 1) {
            prm->keymap->w = key;
            sfText_setString(me->go_up->text, char_to_str(key + 65));
        }
        if (me->mapselect == 2) {
            prm->keymap->d = key;
            sfText_setString(me->go_right->text, char_to_str(key + 65));
        }
        if (me->mapselect == 3) {
            prm->keymap->s = key;
            sfText_setString(me->go_down->text, char_to_str(key + 65));
        }
        if (me->mapselect == 4) {
            prm->keymap->d = key;
            sfText_setString(me->go_left->text, char_to_str(key + 65));
        }
        me->mapselect = 0;
    }
}
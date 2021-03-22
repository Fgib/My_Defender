/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** trigger
*/

#include "my_defender.h"

void trigger_event(struct trigger *trigger, sfEvent event)
{
    int mv_x = event.mouseMove.x;
    int mv_y = event.mouseMove.y;
    int hit_x = event.mouseButton.x;
    int hit_y = event.mouseButton.y;


    if (mv_x >= trigger->coo.x && mv_x <= trigger->coo.x + trigger->size.x &&
    mv_y >= trigger->coo.y && mv_y <= trigger->coo.y + trigger->size.y) {
        sfSprite_setTextureRect(trigger->sprite,
        get_intrect(0, 28 + trigger->state * 56, 28, 28));
    } else {
        sfSprite_setTextureRect(trigger->sprite,
        get_intrect(0, 0 + trigger->state * 56, 28, 28));
    }
    if (hit_x >= trigger->coo.x && hit_x <= trigger->coo.x + trigger->size.x &&
    hit_y >= trigger->coo.y && hit_y <= trigger->coo.y + trigger->size.y &&
    event.type == sfEvtMouseButtonPressed) {
        trigger->state = trigger->state == 0 ? 1 : 0;
    }
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** button
*/

#include "my_defender.h"

int tribush(sfEvent event, struct button *target)
{
    if (click_pre(event, target)) {
        sfSprite_setTextureRect(target->sprite,
        get_intrect(target->size.y * 2 + 4, 0, target->size.x,
        target->size.y));
    } else if (click_is_up(event, target)) {
        sfSprite_setTextureRect(target->sprite,
        get_intrect(target->size.y + 2, 0, target->size.x, target->size.y));
    } else {
        sfSprite_setTextureRect(target->sprite,
        get_intrect(0, 0, target->size.x, target->size.y));
    }
    if (click_rel(event, target)) {
        return 1;
    }
    return 0;
}

int triforce(sfEvent event, struct button *target, sfSound *sound)
{
    if (click_pre(event, target)) {
        sfSprite_setTextureRect(target->sprite,
        get_intrect(0, 2 * 156, 156, 156));
    } else if (click_is_up(event, target)) {
        sfSprite_setTextureRect(target->sprite,
        get_intrect(0, 156, 156, 156));
    } else {
        sfSprite_setTextureRect(target->sprite,
        get_intrect(0, 0, 156, 156));
    }
    if (click_rel(event, target)) {
        sfSound_play(sound);
        return 1;
    }
    return 0;
}
/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_click
*/

#include "my_defender.h"

int click_rel(sfEvent event, struct button *target)
{
    int hit_x = event.mouseButton.x;
    int hit_y = event.mouseButton.y;

    if (event.type != sfEvtMouseButtonReleased)
        return 0;
    if (hit_x >= target->coo.x && hit_x <= target->coo.x + target->size.x &&
    hit_y >= target->coo.y && hit_y <= target->coo.y + target->size.y) {
        return 1;
    }
    return 0;
}

int click_pre(sfEvent event, struct button *target)
{
    int hit_x = event.mouseButton.x;
    int hit_y = event.mouseButton.y;

    if (event.type != sfEvtMouseButtonPressed)
        return 0;
    if (hit_x >= target->coo.x && hit_x <= target->coo.x + target->size.x &&
    hit_y >= target->coo.y && hit_y <= target->coo.y + target->size.y) {
        return 1;
    }
    return 0;
}

int click_is_up(sfEvent event, struct button *target)
{
    int hit_x = event.mouseMove.x;
    int hit_y = event.mouseMove.y;

    if (hit_x >= target->coo.x && hit_x <= target->coo.x + target->size.x &&
    hit_y >= target->coo.y && hit_y <= target->coo.y + target->size.y) {
        return 1;
    }
    return 0;
}
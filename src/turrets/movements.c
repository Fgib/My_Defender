/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** movements
*/

#include "my_defender.h"

void turrets_angle(turrets_t *turrets, int angle)
{
    int i;
    sfIntRect rect;

    angle = (angle - 90 < 0) ? angle + 270 : angle - 90;
    i = angle / 5.625;
    rect = get_intrect(i / 8 * 60, i % 8 * 64, 64, 60);
    sfSprite_setTextureRect(turrets->head, rect);
}

void laser_handler(turrets_t *turrets, int angle, sfVector2f vec)
{
    float x;
    float y;
    float distance = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    int offset_x = turrets->pos.x * 30 + 15;
    int offset_y = turrets->pos.y * 30 - 30;
    sfVector2f vector;

    angle = (angle - 180 < 0) ? angle + 180 : angle - 180;
    x = turrets->pos.x * 1.2 * cosinus(angle);
    y = turrets->pos.y * 1.2 * sinus(angle);
    vector = get_vector(x + offset_x, y + offset_y);
    sfSprite_setTextureRect(turrets->projectile, get_intrect(0, 0, 7, 14));
    sfSprite_setPosition(turrets->projectile, vector);
    sfSprite_setRotation(turrets->projectile, angle - 90.0);
    sfSprite_setScale(turrets->projectile, get_vector(1, distance * 30 / 14));
}
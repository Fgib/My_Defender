/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** trigo
*/

#include "my_defender.h"

float tange(double x)
{
    double in_rad = x * M_PI / 180;
    return (tan(in_rad));
}

float cosinus(double x)
{
    double in_rad = x * M_PI / 180;
    return (cos(in_rad));
}

float sinus(double x)
{
    double in_rad = x * M_PI / 180;
    return (sin(in_rad));
}

pos_t get_location(map_t *map, char to_find)
{
    pos_t res;

    res.x = -1;
    res.y = -1;
    for (int i = 0; i < map->size.x; i++) {
        for (int j = 0; j < map->size.y; j++) {
            res.x = map->vmap[i][j] == to_find ? j : res.x;
            res.y = map->vmap[i][j] == to_find ? i : res.y;
        }
    }
    return res;
}
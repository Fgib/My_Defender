/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_validator
*/

#include "my_defender.h"

int get_by_health(game_t *game, int *ids, int type)
{
    int life = -1;
    int id = -1;

    for (int i = 0; ids[i] != -1; ++i) {
        ennemy_t *en = get_ennemy_by_id(game, ids[i]);
        if (!en)
            continue;
        if (life == -1 || ((type) ? en->health < life : en->health > life)) {
            life = en->health;
            id = en->id;
        }
    }
    return id;
}
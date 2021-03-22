/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** finder
*/

#include "my_defender.h"

int *ennemy_find_in_sphere(game_t *ge, pos_t or, int rad)
{
    int *res;
    int *buff;
    int count = 0;

    for (int i = 0; i < ge->ennemies_count; ++i) {
        pos_t epos = get_vec2(ge->ennemies[i].pos.x, ge->ennemies[i].pos.y);
        if (ge->ennemies[i].health <= 0)
            continue;
        if (sqrt(pow(or.x - epos.x, 2) + pow(or.y - epos.y, 2)) > rad)
            continue;
        buff = malloc(sizeof(int) * (count + 2));
        for (int v = 0; v < count; ++v)
            buff[v] = res[v];
        buff[count] = ge->ennemies[i].id;
        count > 0 ? free(res) : (void)0;
        res = buff;
        count++;
    }
    res = (!count) ? malloc(sizeof(int)) : res;
    res[count] = -1;
    return res;
}
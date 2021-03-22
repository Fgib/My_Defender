/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** constructor
*/

#include "my_defender.h"


sfTexture *get_texture_by_id(gen_t *gen, int id)
{
    if (gen->texture_count <= id - 1 || id - 1 < 0)
        return NULL;
    return gen->textures[id - 1];
}
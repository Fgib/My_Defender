/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** map_gum
*/

#include "my_defender.h"

void gum(map_t *map, vec3_t vec)
{
    if (get_block_by_pos(map, vec))
        delete_block_by_pos(map, vec);
    if (vec.z == 0)
        map->vmap[vec.x][vec.y] = '#';
    sfSprite_destroy(map->sp_map[vec.x][vec.y][vec.z]);
    map->sp_map[vec.x][vec.y][vec.z] = sfSprite_create();
}

void delete_block_by_pos(map_t *map, vec3_t vec)
{
    map_block_t *buff;
    int find = 0;
    map_block_t *ff = get_block_by_pos(map, vec);

    if (!ff)
        return;
    buff = malloc(sizeof(map_block_t) * (map->block_count - 1));
    for (int i = 0; i < map->block_count; ++i) {
        if (!CVECTOR3(vec, get_vector3(map->blocks[i].x,
            map->blocks[i].y, map->blocks[i].layer)))
            buff[i - find] = map->blocks[i];
        else
            find = 1;
    }
    map->block_count--;
    free(map->blocks);
    map->blocks = buff;
}
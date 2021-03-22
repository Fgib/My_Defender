/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** vmap_loader
*/

#include "my_defender.h"

void load_vmap(map_t *map)
{
    char **split = my_str_splitter(my_file_loader(map->path), '\n');

    map->vmap = malloc(sizeof(char *) * (map->size.x + 1));
    for (int i = 0; i < map->size.x; ++i) {
        map->vmap[i] = malloc(sizeof(char *) * (map->size.y + 1));
        for (int j = 0; j < map->size.y; j++)
            map->vmap[i][j] = '#';
        map->vmap[i][map->size.y] = '\0';
    }
    map->vmap[map->size.x] = NULL;
    for (int i = 1; split[i] != NULL; ++i)
        analyze_map_data(map, my_str_splitter(split[i], ':'));
}

void analyze_map_data(map_t *map, char **split)
{
    pos_t pos;
    map_block_t block;
    int layer = my_getnbr(split[2]);

    NVECTOR(pos, my_getnbr(split[0]), my_getnbr(split[1]));
    block.x = pos.x;
    block.y = pos.y;
    block.layer = layer;
    block.property = my_getnbr(split[3]);
    block.texture = my_getnbr(split[4]);
    add_map_blocks(map, block);
    if (pos.x > map->size.x || pos.y > map->size.y ||
        (layer != 0 && layer != 3) || !block.property)
        return;
    map->vmap[pos.x][pos.y] = split[3][0];
}

void setup_map_sprite(gen_t *prm, map_t *map, vec3_t pos)
{
    map->sp_map[pos.x][pos.y][pos.z] = sfSprite_create();
    sfSprite_setPosition(map->sp_map[pos.x][pos.y][pos.z],
    get_vector(pos.x * 30, pos.y * 30));
    if (pos.z == 3)
        sfSprite_setTexture(map->sp_map[pos.x][pos.y][3], prm->hitbox, sfTrue);
}
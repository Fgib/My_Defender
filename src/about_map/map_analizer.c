/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** map_analizer
*/

#include "my_defender.h"

void sprite_texture(gen_t *gen, map_t *map, vec3_t pos, int tid)
{
    sfTexture *text = get_texture_by_id(gen, tid);

    if (text == NULL)
        return;
    sfSprite_setTexture(map->sp_map[pos.x][pos.y][pos.z], text, sfTrue);
}

void sprite_property(gen_t *gen, map_t *map, vec3_t p, int tid)
{
    if (tid <= 0)
        return;
    if (tid == 2) {
        sfSprite_setTexture(map->sp_map[p.x][p.y][1], gen->start, sfTrue);
        sfSprite_setOrigin(map->sp_map[p.x][p.y][1], get_vector(30, 30));
    }
    if (tid == 3) {
        sfSprite_setTexture(map->sp_map[p.x][p.y][1], gen->end, sfTrue);
        sfSprite_setOrigin(map->sp_map[p.x][p.y][1], get_vector(30, 30));
    }
    if (tid == 4)
        sfSprite_setTexture(map->sp_map[p.x][p.y][p.z], gen->path, sfTrue);
}

void setup_spmap(gen_t *gen, map_t *map, int i, int j)
{
    for (int k = 0; k < 4; k++) {
        vec3_t pos;
        NVECTOR(pos, i, j);
        pos.z = k;
        setup_map_sprite(gen, map, pos);
    }
}

void load_spmap(gen_t *gen, map_t *map)
{
    char **split = my_str_splitter(my_file_loader(map->path), '\n');

    map->sp_map = malloc(sizeof(sfSprite ***) * map->size.x);
    for (int i = 0; i < map->size.x; ++i) {
        map->sp_map[i] = malloc(sizeof(sfSprite **) * map->size.y);
        for (int j = 0; j < map->size.y; j++) {
            map->sp_map[i][j] = malloc(sizeof(sfSprite *) * 4);
            setup_spmap(gen, map, i, j);
        }
    }
    for (int i = 1; split[i] != NULL; ++i)
        analyze_spmap_data(gen, map, my_str_splitter(split[i], ':'));
}

void analyze_spmap_data(gen_t *gen, map_t *map, char **data)
{
    vec3_t pos;

    pos.z = my_getnbr(data[2]);
    NVECTOR(pos, my_getnbr(data[0]), my_getnbr(data[1]));
    if (pos.x > map->size.x || pos.y > map->size.y || pos.z > 2)
        return;
    sprite_texture(gen, map, pos, my_getnbr(data[4]));
    sprite_property(gen, map, pos, my_getnbr(data[3]));
}
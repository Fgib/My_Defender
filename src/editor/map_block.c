/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** map_block
*/

#include "my_defender.h"

void add_map_blocks(map_t *map, map_block_t block)
{
    map_block_t *buff;
    map_block_t *temp = get_block_by_pos(map,
    get_vector3(block.x, block.y, block.layer));

    if (temp != NULL) {
        temp->property = block.property;
        temp->texture = block.texture;
        return;
    }
    buff = malloc(sizeof(map_block_t) * (map->block_count + 1));
    for (int i = 0; i < map->block_count; ++i)
        buff[i] = map->blocks[i];
    buff[map->block_count] = block;
    if (map->block_count > 0)
        free(map->blocks);
    map->blocks = buff;
    map->block_count++;
}

map_block_t *get_block_by_pos(map_t *map, vec3_t pos)
{
    for (int i = 0; i < map->block_count; ++i)
        if (map->blocks[i].x == pos.x && map->blocks[i].y == pos.y
            && map->blocks[i].layer == pos.z)
            return &map->blocks[i];
    return NULL;
}

void save_blocks(map_t *map)
{
    int fd;
    char *size = get_size(map);

    CLEARFILE(map->path);
    fd = open(map->path, O_WRONLY, O_TRUNC);
    write(fd, size, my_strlen(size));
    for (int i = 0; i < map->block_count; i++) {
        char *temp = get_block(map->blocks[i]);
        if (i < map->block_count - 1)
            temp = str_add(temp, "\n");
        write(fd, temp, my_strlen(temp));
    }
    close(fd);
}

char *get_size(map_t *map)
{
    int len = 2 + score_debugger(map->size.x) + score_debugger(map->size.y);
    char *block = malloc(sizeof(char) * len);

    block = str_add("", get_str(map->size.x));
    block = str_add(block, ":");
    block = str_add(block, get_str(map->size.y));
    block = str_add(block, "\n");
    return block;
}

char *get_block(map_block_t b)
{
    int len = 5 + score_debugger(b.x) + score_debugger(b.y) +
    score_debugger(b.layer) + score_debugger(b.property) +
    score_debugger(b.texture);
    char *block = malloc(sizeof(char) * len);

    block = str_add("", get_str(b.x));
    block = str_add(block, ":");
    block = str_add(block, get_str(b.y));
    block = str_add(block, ":");
    block = str_add(block, get_str(b.layer));
    block = str_add(block, ":");
    block = str_add(block, get_str(b.property));
    block = str_add(block, ":");
    block = str_add(block, get_str(b.texture));
    return block;
}
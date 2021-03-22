/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** paint
*/

#include "my_defender.h"

void paint_start(gen_t *prm, editor_eng_t *eng)
{
    pos_t pos = get_location(&eng->map, '2');
    map_block_t b;

    if (pos.x != -1 && pos.y != 1)
        return;
    b.x = eng->last_mouse.y;
    b.y = eng->last_mouse.x;
    b.texture = 0;
    b.layer = 0;
    b.property = 2;
    eng->map.vmap[b.x][b.y] = '2';
    add_map_blocks(&eng->map, b);
    sfSprite_setTexture(eng->map.sp_map[b.x][b.y][1], prm->start, sfTrue);
    sfSprite_setOrigin(eng->map.sp_map[b.x][b.y][1], get_vector(30, 30));
}

void paint_hitbox(editor_eng_t *eng)
{
    map_block_t b;

    b.x = eng->last_mouse.y;
    b.y = eng->last_mouse.x;
    if (eng->map.vmap[b.x][b.y] != '#' && eng->map.vmap[b.x][b.y] != '1')
        return;
    b.texture = 0;
    b.layer = 3;
    b.property = (eng->map.vmap[b.x][b.y] == '#') ? 1 : 0;
    eng->map.vmap[b.x][b.y] = (eng->map.vmap[b.x][b.y] == '#') ? '1' : '#';
    add_map_blocks(&eng->map, b);
}

void paint_end(gen_t *prm, editor_eng_t *eng)
{
    pos_t pos = get_location(&eng->map, '3');
    map_block_t b;

    if (pos.x != -1 && pos.y != 1)
        return;
    b.x = eng->last_mouse.y;
    b.y = eng->last_mouse.x;
    b.texture = 0;
    b.layer = 0;
    b.property = 3;
    eng->map.vmap[b.x][b.y] = '3';
    add_map_blocks(&eng->map, b);
    sfSprite_setTexture(eng->map.sp_map[b.x][b.y][1], prm->end, sfTrue);
    sfSprite_setOrigin(eng->map.sp_map[b.x][b.y][1], get_vector(30, 30));
}

void paint_path(gen_t *prm, editor_eng_t *eng)
{
    map_block_t b;

    b.x = eng->last_mouse.y;
    b.y = eng->last_mouse.x;
    b.texture = 0;
    b.layer = 0;
    b.property = 4;
    eng->map.vmap[b.x][b.y] = '4';
    add_map_blocks(&eng->map, b);
    sfSprite_setTexture(eng->map.sp_map[b.x][b.y][0], prm->path, sfTrue);
    sfSprite_setOrigin(eng->map.sp_map[b.x][b.y][1], get_vector(30, 30));
}

void default_paint(gen_t *prm, editor_eng_t *eng)
{
    map_block_t b;

    b.x = eng->last_mouse.y;
    b.y = eng->last_mouse.x;
    b.layer = eng->layer;
    b.property = 0;
    b.texture = eng->select;
    sfSprite_setTexture(eng->map.sp_map[b.x][b.y][eng->layer],
    get_texture_by_id(prm, eng->select), sfTrue);
    add_map_blocks(&eng->map, b);
}
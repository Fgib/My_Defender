/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** constructor2
*/

#include "my_defender.h"

int create_turrets(game_t *ge, int id, pos_t pos)
{
    turrets_t new;
    turrets_t *buff;

    if (!setup_turrets_struct(ge, &new, id, pos))
        return 0;
    ge->turrets_count++;
    ge->turret_id++;
    buff = malloc(sizeof(turrets_t) * (ge->turrets_count + 1));
    for (int i = 0; i < ge->turrets_count - 1; ++i)
        buff[i] = ge->turrets[i];
    buff[ge->turrets_count - 1] = new;
    if (ge->turrets_count - 1)
        free(ge->turrets);
    ge->turrets = buff;
    return 1;
}

int setup_turrets_struct(game_t *ge, turrets_t *new, int id, pos_t pos)
{
    if (ge->turrets_dic_count <= id)
        return 0;
    new->type = ge->turrets_dic[id].type;
    new->range = ge->turrets_dic[id].range;
    new->level = 1;
    new->damage = ge->turrets_dic[id].damage;
    new->fire_rate = ge->turrets_dic[id].fire_rate;
    new->target_type = 0;
    new->last_target = -1;
    new->base = ge->turrets_dic[id].base;
    new->head = get_sprite(ge->turrets_dic[id].head_path);
    new->projectile = get_sprite(ge->turrets_dic[id].proj_path);
    new->id = ge->turret_id;
    new->fire_pos = 1;
    new->price = ge->turrets_dic[id].price;
    turrets_angle(new, 0);
    SVECTOR(new->pos, pos);
    return 1;
}
/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** constructor
*/

#include "my_defender.h"

int load_turrets(game_t *game, char *data)
{
    char *memory = my_file_loader(data);
    char **split;

    if (!turrets_are_valid(data))
        return 0;
    split = my_str_splitter(memory, '\n');
    for (int i = 0; split[i] != NULL; ++i)
        add_to_turrets(game, my_str_splitter(split[i], ':'), i);
    return 1;
}

turrets_t *get_turret_by_id(game_t *game, int id)
{
    for (int i = 0; i < game->turrets_count; ++i)
        if (game->turrets[i].id == id)
            return &game->turrets[i];
    return NULL;
}

turrets_t *get_turret_by_pos(game_t *game, pos_t pos)
{
    for (int i = 0; i < game->turrets_count; ++i)
        if (CVECTOR(game->turrets[i].pos, pos))
            return &game->turrets[i];
    return NULL;
}

void delete_turret_by_id(game_t *game, int id)
{
    turrets_t *buff;
    int i;
    int find = 0;
    turrets_t *ff = get_turret_by_id(game, id);

    if (!ff)
        return;
    buff = malloc(sizeof(turrets_t) * (game->turrets_count - 1));
    for (i = 0; i < game->turrets_count; ++i)
        if (game->turrets[i].id != id)
            buff[i - find] = game->turrets[i];
        else
            find = 1;
    game->turrets_count--;
    free(game->turrets);
    game->turrets = buff;
}

void add_to_turrets(game_t *game, char **data, int v)
{
    turrets_t new;
    turrets_t *buff = malloc(sizeof(turrets_t) * (game->turrets_dic_count + 1));
    int i;

    new.type = my_getnbr(data[0]);
    new.range = my_getnbr(data[1]);
    new.damage = my_getnbr(data[2]);
    new.fire_rate = my_getnbr(data[3]);
    new.price = my_getnbr(data[4]);
    new.base = get_sprite(data[5]);
    new.head_path = data[6];
    new.proj_path = data[7];
    game->turrets_btn[v]->icon = get_sprite(data[8]);
    new.last_target = -1;
    for (i = 0; i < game->turrets_dic_count; ++i)
        buff[i] = game->turrets_dic[i];
    buff[i] = new;
    if (game->turrets_dic_count)
        free(game->turrets_dic);
    game->turrets_dic = buff;
    game->turrets_dic_count++;
}
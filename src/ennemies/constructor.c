/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** ennemies
*/

#include "my_defender.h"

void create_ennemy(game_t *ge, int id)
{
    ennemy_t new;
    ennemy_t *buff;

    if (!setup_ennemy_struct(ge, &new, id))
        return;
    ge->ennemies_count++;
    new.id = ge->ennemy_id;
    ge->ennemy_id++;
    buff = malloc(sizeof(ennemy_t) * (ge->ennemies_count + 1));
    for (int i = 0; i < ge->ennemies_count - 1; ++i)
        buff[i] = ge->ennemies[i];
    buff[ge->ennemies_count - 1] = new;
    if (ge->ennemies_count - 1)
        free(ge->ennemies);
    ge->ennemies = buff;
}

int setup_ennemy_struct(game_t *ge, ennemy_t *new, int id)
{
    if (ge->ennemies_dic_count <= id)
        return 0;
    new->type = ge->ennemies_dic[id].type;
    new->health = ge->ennemies_dic[id].health;
    new->armor = ge->ennemies_dic[id].armor;
    new->speed = ge->ennemies_dic[id].speed;
    new->skin = get_sprite(ge->ennemies_dic[id].skin_path);
    new->skin = get_sprite(ge->ennemies_dic[id].skin_path);
    new->dead = get_sprite(ge->ennemies_dic[id].dead_path);
    new->credit = ge->ennemies_dic[id].credit;
    new->skin_id = 0;
    SVECTOR(new->pos, ge->start);
    NVECTOR(new->pixel, 0, 0);
    NVECTOR(new->last_dir, 1, 0);
    return 1;
}

ennemy_t *get_ennemy_by_id(game_t *game, int id)
{
    for (int i = 0; i < game->ennemies_count; ++i)
        if (game->ennemies[i].id == id)
            return &game->ennemies[i];
    return NULL;
}

void delete_ennemy_by_id(game_t *game, int id)
{
    ennemy_t *buff;
    int i;
    int find = 0;
    ennemy_t *ff = get_ennemy_by_id(game, id);

    if (!ff)
        return;
    buff = malloc(sizeof(ennemy_t) * (game->ennemies_count - 1));
    for (i = 0; i < game->ennemies_count; ++i)
        if (game->ennemies[i].id != id)
            buff[i - find] = game->ennemies[i];
        else
            find = 1;
    game->ennemies_count--;
    free(game->ennemies);
    game->ennemies = buff;
}

void set_ennemy_dictionnary(game_t *game, char *file)
{
    char **split;

    split = my_str_splitter(file, '|');
    for (int i = 0; i < my_char_nbfind('|', file) + 1; ++i)
        add_to_dico(game, my_str_splitter(split[i], ':'));
}
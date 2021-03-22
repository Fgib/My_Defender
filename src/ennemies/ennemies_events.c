/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** events
*/

#include "my_defender.h"

int ennemy_finded_goal(game_t *game, ennemy_t *en)
{
    pos_t move = en->last_dir;
    pos_t rpos = get_rev_move(en->last_dir);
    int i;

    for (i = 0; i < 4; ++i) {
        pos_t buff = en->pos;
        AVECTOR(buff, move.x, move.y);
        if (CVECTOR(buff, game->target) && !CVECTOR(move, rpos))
            break;
        move = get_next_move(move);
    }
    return (i == 4) ? 0 : 1;
}

void check_ennemies_goal(game_t *game)
{
    for (int i = 0; i < game->ennemies_count; ++i) {
        if (!ennemy_finded_goal(game, &(game->ennemies[i])))
            continue;
        game->life -= game->ennemies[i].health;
        delete_ennemy_by_id(game, game->ennemies[i].id);
    }
}

void add_to_dico(game_t *game, char **settings)
{
    ennemy_t new;
    ennemy_t *buff = malloc(sizeof(ennemy_t) * (game->ennemies_dic_count + 1));
    int i;

    new.type = my_getnbr(settings[0]);
    new.health = my_getnbr(settings[1]);
    new.armor = my_getnbr(settings[2]);
    new.speed = my_getnbr(settings[3]);
    new.credit = my_getnbr(settings[4]);
    new.skin_path = settings[5];
    new.dead_path = settings[6];
    for (i = 0; i < game->ennemies_dic_count; ++i)
        buff[i] = game->ennemies_dic[i];
    buff[i] = new;
    if (game->ennemies_dic_count)
        free(game->ennemies_dic);
    game->ennemies_dic = buff;
    game->ennemies_dic_count++;
}
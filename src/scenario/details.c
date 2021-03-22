/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** details
*/

#include "my_defender.h"

void get_scenario_detail(gen_t *gen, scenario_t *scen, char *path)
{
    scen_detail_t det;
    char *memory = my_file_loader(path);
    char **split = my_str_splitter(memory, '\n');

    det.ennemy_count = 0;
    det.mpath = split[1];
    det.map = get_map_by_path(gen->start_menu, det.mpath);
    det.wave_count = get_wave_count(my_str_splitter(split[5], '|'));
    det.credit = my_getnbr(split[3]);
    det.difficulty = 1;
    get_ennemy_dic(&det, split[4]);
    scen->detail = det;
}

int get_wave_count(char **split)
{
    int i = 0;

    for (; split[i] != NULL; ++i);
    return i;
}

void get_ennemy_dic(scen_detail_t *det, char *dic)
{
    char **split = my_str_splitter(dic, '|');

    for (int i = 0; split[i] != NULL; ++i)
        add_to_scen_dico(det, split[i]);
}

void add_to_scen_dico(scen_detail_t *det, char *split)
{
    char **temp = my_str_splitter(split, ':');
    ennemy_t new;
    ennemy_t *buff = malloc(sizeof(ennemy_t) * (det->ennemy_count + 1));
    int i;

    new.type = my_getnbr(temp[0]);
    new.health = my_getnbr(temp[1]);
    new.armor = my_getnbr(temp[2]);
    new.speed = my_getnbr(temp[3]);
    new.credit = my_getnbr(temp[4]);
    new.skin_path = temp[5];
    new.dead_path = temp[6];
    for (i = 0; i < det->ennemy_count; ++i)
        buff[i] = det->ennemy_dic[i];
    buff[i] = new;
    if (det->ennemy_count)
        free(det->ennemy_dic);
    det->ennemy_dic = buff;
    det->ennemy_count++;
}
/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** load
*/

#include "my_defender.h"

int load_scenario(gen_t *prm, char *file)
{
    char *memory = my_file_loader(file);
    char **split;

    if (!scenario_is_valid(file))
        return 0;
    split = my_str_splitter(memory, '\n');
    prm->game_eng->map = get_map_by_path(prm->start_menu, split[1]);
    if (!load_turrets(prm->game_eng, split[2]))
        return 0;
    prm->game_eng->credit = my_getnbr(split[3]);
    set_ennemy_dictionnary(prm->game_eng, split[4]);
    load_waves(prm->game_eng, split[5]);
    return 1;
}

void load_waves(game_t *game, char *file)
{
    char **split;

    split = my_str_splitter(file, '|');
    for (int i = 0; i < my_char_nbfind('|', file) + 1; ++i)
        add_to_waves(game, my_str_splitter(split[i], ';'));
}

void add_to_waves(game_t *game, char **settings)
{
    wave_t new;
    wave_t *buff = malloc(sizeof(wave_t) * (game->waves.wave_count + 1));
    int i;

    new.random = my_getnbr(settings[0]);
    for (i = 0; settings[i] != NULL; ++i);
    new.count = i - 1;
    new.meta = malloc(sizeof(int *) * i);
    for (i = 0; settings[i + 1] != NULL; ++i) {
        char **opt = my_str_splitter(settings[i + 1], ':');
        new.meta[i] = malloc(sizeof(int) * 2);
        new.meta[i][0] = my_getnbr(opt[0]);
        new.meta[i][1] = my_getnbr(opt[1]);
    }
    for (i = 0; i < game->waves.wave_count; ++i)
        buff[i] = game->waves.waves[i];
    buff[i] = new;
    if (game->waves.wave_count)
        free(game->waves.waves);
    game->waves.waves = buff;
    game->waves.wave_count++;
}
/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** scenario_validator
*/

#include "my_defender.h"

int scenario_is_valid(char *path)
{
    char *memory = my_file_loader(path);
    char **split;

    if (memory[0] == '\0')
        return 0;
    split = my_str_splitter(memory, '\n');
    for (int i = 0; i < 6; ++i)
        if (!split[i])
            return 0;
    if (!check_file(split[1]) || !check_file(split[2]))
        return 0;
    if (!map_is_valid(split[1]))
        return 0;
    if (!my_str_isnum(split[3]) || !dictionnary_is_valid(split[4]))
        return 0;
    if (!wave_are_valid(split[5]))
        return 0;
    return 1;
}

int dictionnary_is_valid(char *data)
{
    char **split = my_str_splitter(data, '|');
    int bad = 0;

    for (int i = 0; split[i] != NULL; ++i) {
        char **temp = my_str_splitter(split[i], ':');
        bad += dic_data_null(temp);
        bad += dic_data_valid(temp);
    }
    return (bad) ? 0 : 1;
}

int dic_data_null(char **data)
{
    for (int i = 0; i < 7; ++i)
        if (!data[i])
            return 1;
    return 0;
}

int dic_data_valid(char **data)
{
    int bad = 0;

    for (int i = 0; i < 5; ++i)
        bad -= my_str_isnum(data[i]) - 1;
    for (int i = 5; i < 7; ++i)
        bad += (!check_file(data[i])) ? 1 : 0;
    return (bad) ? 1 : 0;
}
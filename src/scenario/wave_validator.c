/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** wave_validator
*/

#include "my_defender.h"

int wave_are_valid(char *data)
{
    char **split = my_str_splitter(data, '|');
    int bad = 0;

    for (int i = 0; split[i] != NULL; ++i) {
        char **temp = my_str_splitter(split[i], ';');
        bad += (split[i][0] == '1' || split[i][0] == '0') ? 0 : 1;
        for (int v = 1; temp[v] != NULL; ++v) {
            char **data = my_str_splitter(temp[v], ':');
            bad += wave_data_null(data);
            bad += wave_data_valid(data);
        }
    }
    return (bad) ? 0 : 1;
}

int wave_data_null(char **data)
{
    for (int i = 0; i < 2; ++i)
        if (!data[i])
            return 1;
    return 0;
}

int wave_data_valid(char **data)
{
    int bad = 0;

    for (int i = 0; i < 2; ++i)
        bad -= my_str_isnum(data[i]) - 1;
    return (bad) ? 1 : 0;
}
/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** map_validator
*/

#include "my_defender.h"

int map_is_valid(char *path)
{
    char *memory = my_file_loader(path);
    char **split;
    if (memory[0] == '\0')
        return 0;
    split = my_str_splitter(memory, '\n');
    if (!split[0] || !split[1])
        return 0;
    for (int i = 1; split[i] != NULL; i++) {
        char **temp = my_str_splitter(split[i], ':');
        if (map_data_null(temp))
            return 0;
        if (!map_data_valid(temp))
            return 0;
    }
    return 1;
}

int map_data_null(char **data)
{
    for (int i = 0; i < 5; ++i)
        if (!data[i])
            return 1;
    return 0;
}

int map_data_valid(char **data)
{
    for (int i = 0; i < 5; ++i)
        if (!my_str_isnum(data[i]))
            return 0;
    return 1;
}
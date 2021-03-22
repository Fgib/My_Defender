/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** turret_validator
*/

#include "my_defender.h"

int turrets_are_valid(char *path)
{
    char *memory = my_file_loader(path);
    char **split;
    int bad = 0;

    if (memory[0] == '\0')
        return 0;
    split = my_str_splitter(memory, '\n');
    for (int i = 0; split[i] != NULL; ++i) {
        char **temp = my_str_splitter(split[i], ':');
        bad += data_are_null(temp);
        bad += check_data_validity(temp);
    }
    return (bad) ? 0 : 1;
}

int data_are_null(char **split)
{
    for (int i = 0; i < 9; ++i)
        if (!split[i])
            return 1;
    return 0;
}

int check_data_validity(char **data)
{
    int bad = 0;

    for (int i = 0; i < 5; ++i)
        bad -= my_str_isnum(data[i]) - 1;
    for (int i = 5; i < 9; ++i)
        bad += (!check_file(data[i])) ? 1 : 0;
    return (bad) ? 1 : 0;
}
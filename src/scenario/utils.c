/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** utils
*/

#include "my_defender.h"

char *get_sname(char *path)
{
    char *mem = my_file_loader(path);
    char **split = my_str_splitter(mem, '\n');

    if (mem[0] == '\0' || !split[0])
        return mem;
    return split[0];
}
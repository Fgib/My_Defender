/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** dir
*/

#include "my_defender.h"

void get_scenarios(gen_t *gen, start_menu_t *menu)
{
    struct dirent *dir;
    DIR *d = opendir("scenarios");

    if (menu->scenario_count)
        free(menu->scenarios);
    menu->scenario_count = 0;
    if (d) {
        while ((dir = readdir(d)) != NULL)
            check_for_scenario(gen, menu, dir);
        closedir(d);
    }
}

void check_for_scenario(gen_t *gen, start_menu_t *menu, struct dirent *dir)
{
    char *temp = malloc(sizeof(char) *
    (my_strlen("scenarios/") + my_strlen(dir->d_name)));
    if (!my_strcmp(dir->d_name, ".") || !my_strcmp(dir->d_name, ".."))
        return;
    temp = str_add("scenarios/", dir->d_name);
    scenario_is_valid(temp) ? add_to_scena(gen, menu, temp) : (void)0;
}

void add_to_scena(gen_t *gen, start_menu_t *menu, char *path)
{
    scenario_t new;
    scenario_t *buff;

    new.path = path;
    new.valid = scenario_is_valid(path);
    new.name = get_sname(path);
    get_scenario_detail(gen, &new, path);
    menu->scenario_count++;
    buff = malloc(sizeof(scenario_t) * (menu->scenario_count + 1));
    for (int i = 0; i < menu->scenario_count - 1; ++i)
        buff[i] = menu->scenarios[i];
    buff[menu->scenario_count - 1] = new;
    if (menu->scenario_count - 1)
        free(menu->scenarios);
    menu->scenarios = buff;
}
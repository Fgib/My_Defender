/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** map_loader
*/

#include "my_defender.h"

void get_maps_loop(gen_t *gen, start_menu_t *menu, DIR *d)
{
    struct dirent *dir;

    while ((dir = readdir(d)) != NULL) {
        if (!my_strcmp(dir->d_name, ".") || !my_strcmp(dir->d_name, ".."))
            continue;
        char *temp = malloc(sizeof(char) * (my_strlen("maps/") +
        my_strlen(dir->d_name)));
        temp = str_add("maps/", dir->d_name);
        map_is_valid(temp) ? add_to_map(gen, menu, temp, dir->d_name) : (void)0;
    }
    closedir(d);
}

void get_maps(gen_t *gen, start_menu_t *menu)
{
    DIR *d = opendir("maps");

    if (menu->map_count)
        free(menu->maps);
    menu->map_count = 0;
    if (d) {
        get_maps_loop(gen, menu, d);
    }
}

void add_to_map(gen_t *gen, start_menu_t *menu, char *path, char *name)
{
    map_t new;
    map_t *buff;
    pos_t size = get_map_size(path);
    new.path = my_strdup(path);
    new.name = my_strdup(name);
    new.block_count = 0;
    SVECTOR(new.size, size);
    load_vmap(&new);
    load_spmap(gen, &new);
    menu->map_count++;
    buff = malloc(sizeof(scenario_t) * (menu->map_count + 1));
    for (int i = 0; i < menu->map_count - 1; ++i)
        buff[i] = menu->maps[i];
    buff[menu->map_count - 1] = new;
    if (menu->map_count - 1)
        free(menu->maps);
    menu->maps = buff;
}

pos_t get_map_size(char *path)
{
    char **split = my_str_splitter(my_file_loader(path), '\n');
    pos_t pos;

    split = my_str_splitter(split[0], ':');
    pos.x = my_getnbr(split[0]);
    pos.y = my_getnbr(split[1]);
    return pos;
}

map_t *get_map_by_path(start_menu_t *menu, char *path)
{
    for (int i = 0; i < menu->map_count; ++i) {
        if (my_strcmp(menu->maps[i].path, path) == 0)
            return &menu->maps[i];
    }
    return NULL;
}
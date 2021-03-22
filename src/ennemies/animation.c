/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** animation
*/

#include "my_defender.h"

int en_or(ennemy_t en)
{
    if (en.last_dir.x == 0 && en.last_dir.y == -1)
        return 0;
    if (en.last_dir.x == 1 && en.last_dir.y == 0)
        return 1;
    if (en.last_dir.x == 0 && en.last_dir.y == 1)
        return 2;
    if (en.last_dir.x == -1 && en.last_dir.y == 0)
        return 3;
    return -1;
}

void ennemies_animation(struct gen *prm)
{
    for (int i = 0; i < prm->game_eng->ennemies_count; i++) {
        if (prm->game_eng->ennemies[i].health > 0) {
            float size_ratio = prm->game_eng->ennemies[i].armor / 100.0;
            sfSprite_setOrigin(prm->game_eng->ennemies[i].skin,
            get_vector(79, 79));
            sfSprite_setTextureRect(prm->game_eng->ennemies[i].skin,
            get_intrect(en_or(prm->game_eng->ennemies[i]) * 158,
            prm->game_eng->ennemies[i].skin_id / 2 * 202, 158, 158));
            sfSprite_setScale(prm->game_eng->ennemies[i].skin,
            get_vector(size_ratio, size_ratio));
            prm->game_eng->ennemies[i].skin_id +=
            prm->game_eng->ennemies[i].skin_id < 31 ? 1 : -31;
        }
    }
}
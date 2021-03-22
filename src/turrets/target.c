/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** target
*/

#include "my_defender.h"

int fire_ennemy(game_t *game, turrets_t *self, sound_t *sound)
{
    ennemy_t *en = get_ennemy_to_target(game, self);
    sfVector2f vec;
    sfVector2f temp;

    if (!self || !en) {
        sfSprite_setTextureRect(self->projectile, get_intrect(-28, -28, 7, 14));
        return 0;
    }
    NVECTOR(temp, en->pos.x, en->pos.y);
    AVECTOR(temp, en->pixel.x * (10.0/3.0) / 100,
    en->pixel.y * (10.0/3.0) / 100);
    GVECTOR(vec, self->pos, temp);
    if (!the_return_of_fire(self, sound, vec))
        return 0;
    en->health -= self->damage;
    if (en->health <= 0) {
        game->credit += en->credit;
        game->gear++;
    }
    self->last_target = en->id;
    return 1;
}

int the_return_of_fire(turrets_t *self, sound_t *sound, sfVector2f v)
{
    float angle = atan2(v.y, v.x) * 180 / M_PI + 180;

    turrets_angle(self, (int)angle);
    if (self->fire_pos < self->fire_rate) {
        sfSprite_setTextureRect(self->projectile,
        get_intrect(-28, -28, 7, 14));
        self->fire_pos++;
        return 0;
    }
    laser_handler(self, (int)angle, v);
    sfSound_play(sound->laser);
    self->fire_pos = 1;
    return 1;
}

ennemy_t *get_ennemy_to_target(game_t *game, turrets_t *self)
{
    ennemy_t *en;
    int *ids = ennemy_find_in_sphere(game, self->pos, self->range);
    int find = 0;

    for (int i = 0; ids[i] != -1; ++i)
        if (ids[i] == self->last_target)
            find = 1;
    if (!self)
        return NULL;
    if (find)
        en = get_ennemy_by_id(game, self->last_target);
    else {
        switch (self->target_type) {
        case 0: en = get_ennemy_by_id(game, get_by_health(game, ids, 0));
            break;
        case 1: en = get_ennemy_by_id(game, get_by_health(game, ids, 1));
            break;
        default: en = get_ennemy_by_id(game, ids[0]);
        }
    }
    return en;
}
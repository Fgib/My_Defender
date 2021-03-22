/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** sound_level
*/

#include "my_defender.h"

void sound_level(gen_t *prm)
{
    float mult = prm->setti_menu->main_volume->value / 50.0;

    sfMusic_setVolume(prm->sound->wind, prm->setti_menu->wind->value * mult);
    sfMusic_setVolume(prm->sound->intro, prm->setti_menu->music->value * mult);
    sfMusic_setVolume(prm->sound->alert, prm->setti_menu->alerts->value * mult);
    sfMusic_setVolume(prm->sound->siren, prm->setti_menu->alerts->value * mult);
    sfMusic_setVolume(prm->sound->ambiance,
    prm->setti_menu->music->value * mult);
    sfSound_setVolume(prm->sound->laser,
    prm->setti_menu->effects->value * mult);
    sfSound_setVolume(prm->sound->wave_end,
    prm->setti_menu->alerts->value * mult);
    sfSound_setVolume(prm->sound->btn_press,
    prm->setti_menu->effects->value * mult);
    sfSound_setVolume(prm->sound->explosion,
    prm->setti_menu->effects->value * mult);
    sfSound_setVolume(prm->sound->impossible,
    prm->setti_menu->effects->value * mult);
    sfSound_setVolume(prm->sound->bitter_death,
    prm->setti_menu->ennemis->value * mult);
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_game2
*/

#include "my_defender.h"

void setup_money_ui(game_t *temp)
{
    temp->transp_fric = get_sprite("assets/pics/tri_button.png");
    sfSprite_setTextureRect(temp->transp_fric, get_intrect(0, 0, 156, 156));
    sfSprite_setPosition(temp->transp_fric, get_vector(1764, 0));
    sfSprite_setScale(temp->transp_fric, get_vector(1, 0.6));
    temp->gear_s = get_sprite("assets/pics/gear.png");
    temp->credit_s = get_sprite("assets/pics/coin.png");
    sfSprite_setPosition(temp->gear_s, get_vector(1870, 40));
    sfSprite_setPosition(temp->credit_s, get_vector(1870, 0));
}

void setup_turret_bar(game_t *temp)
{
    temp->transp = initialize_button(0, 0, 156, 156);
    temp->transp->sprite = get_sprite("assets/pics/tri_button.png");
    sfSprite_setTextureRect(temp->transp->sprite, get_intrect(0, 0, 156, 156));
    temp->turrets_btn = malloc(sizeof(struct button) * 6);
    for (int i = 0; i < 6; i++) {
        temp->turrets_btn[i] = initialize_button(0, 0, 156, 156);
        temp->turrets_btn[i]->sprite = get_sprite("assets/pics/tri_button.png");
        sfSprite_setTextureRect(temp->turrets_btn[i]->sprite,
        get_intrect(0, 0, 156, 156));
        sfSprite_setScale(temp->turrets_btn[i]->sprite, get_vector(0.9, 0.9));
    }
}
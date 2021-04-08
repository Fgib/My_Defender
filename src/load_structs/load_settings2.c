/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_settings2
*/

#include "my_defender.h"

void load_text_settings_keymap_b(setti_menu_t *temp)
{
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");

    temp->t_up = sfText_create();
    temp->t_right = sfText_create();
    temp->t_down = sfText_create();
    temp->t_left = sfText_create();
    sfText_setString(temp->t_up, "Move up");
    sfText_setString(temp->t_right, "Move right");
    sfText_setString(temp->t_down, "Move down");
    sfText_setString(temp->t_left, "Move left");
    sfText_setFont(temp->t_up, font);
    sfText_setFont(temp->t_right, font);
    sfText_setFont(temp->t_down, font);
    sfText_setFont(temp->t_left, font);
    sfText_setPosition(temp->t_up, get_vector(820, 365));
    sfText_setPosition(temp->t_right, get_vector(820, 465));
    sfText_setPosition(temp->t_down, get_vector(820, 565));
    sfText_setPosition(temp->t_left, get_vector(820, 665));
}

void load_text_settings_keymap_bis(setti_menu_t *temp)
{
    sfSprite_setScale(temp->go_up->sprite, get_vector(0.45, 0.45));
    sfSprite_setScale(temp->go_right->sprite, get_vector(0.45, 0.45));
    sfSprite_setScale(temp->go_down->sprite, get_vector(0.45, 0.45));
    sfSprite_setScale(temp->go_left->sprite, get_vector(0.45, 0.45));
    load_text_btn(temp->go_up, (int[4]){20, 15, 40}, "Z");
    load_text_btn(temp->go_right, (int[4]){20, 15, 40}, "Q");
    load_text_btn(temp->go_down, (int[4]){20, 15, 40}, "S");
    load_text_btn(temp->go_left, (int[4]){20, 15, 40}, "A");
}
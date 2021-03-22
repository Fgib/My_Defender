/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_turrets_info
*/

#include "my_defender.h"

turret_info_t setup_info_bubble(void)
{
    turret_info_t temp;
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");

    temp.background = get_sprite("assets/pics/tri_button.png");
    sfSprite_setPosition(temp.background, get_vector(75, 75));
    sfSprite_setScale(temp.background, get_vector(3, 6));
    sfSprite_setTextureRect(temp.background, get_intrect(0, 0, 156, 156));
    setup_info_bubble2(&temp, font);
    setup_info_bubble3(&temp);
    return temp;
}

void setup_info_bubble2(turret_info_t *info, sfFont *font)
{
    info->id = sfText_create();
    info->level = sfText_create();
    info->damage = sfText_create();
    info->fire_rate = sfText_create();
    info->range = sfText_create();
    sfText_setPosition(info->id, get_vector(125, 450));
    sfText_setPosition(info->level, get_vector(125, 540));
    sfText_setPosition(info->damage, get_vector(125, 630));
    sfText_setPosition(info->fire_rate, get_vector(125, 720));
    sfText_setPosition(info->range, get_vector(125, 810));
    sfText_setCharacterSize(info->id, 25);
    sfText_setCharacterSize(info->level, 25);
    sfText_setCharacterSize(info->damage, 25);
    sfText_setCharacterSize(info->fire_rate, 25);
    sfText_setCharacterSize(info->range, 25);
    sfText_setFont(info->id, font);
    sfText_setFont(info->level, font);
    sfText_setFont(info->damage, font);
    sfText_setFont(info->fire_rate, font);
    sfText_setFont(info->range, font);
}

void setup_info_bubble3(turret_info_t *info)
{
    info->sell = initialize_button(127, 350, 156, 156);
    info->close = initialize_button(231, 900, 156, 156);
    info->upgrade = initialize_button(344, 350, 156, 156);
    info->sell->sprite = get_sprite("assets/pics/tri_button.png");
    info->upgrade->sprite = get_sprite("assets/pics/tri_button.png");
    info->close->sprite = get_sprite("assets/pics/tri_button.png");
    sfSprite_setPosition(info->sell->sprite, info->sell->coo);
    sfSprite_setPosition(info->close->sprite, info->close->coo);
    sfSprite_setPosition(info->upgrade->sprite, info->upgrade->coo);
    sfSprite_setScale(info->sell->sprite, get_vector(1, 0.45));
    sfSprite_setScale(info->close->sprite, get_vector(1, 0.45));
    sfSprite_setScale(info->upgrade->sprite, get_vector(1, 0.45));
    sfSprite_setTextureRect(info->sell->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setTextureRect(info->close->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setTextureRect(info->upgrade->sprite, get_intrect(0, 0, 156, 156));
    load_text_btn(info->sell, (int[4]){55, 22, 20}, "Sell");
    load_text_btn(info->close, (int[4]){50, 22, 20}, "Close");
    load_text_btn(info->upgrade, (int[4]){34, 22, 20}, "Upgrade");
}
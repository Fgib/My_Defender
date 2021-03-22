/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** init_slider
*/

#include "my_defender.h"

void init_slider_name(slider_t *temp, int px, int py, char *name)
{
    temp->text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");

    sfText_setPosition(temp->text, get_vector(px, py));
    sfText_setCharacterSize(temp->text, 20);
    sfText_setString(temp->text, name);
    sfText_setFont(temp->text, font);
}

void init_slider_digit(slider_t *temp, int px, int py, int val)
{
    temp->digit = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");

    sfText_setPosition(temp->digit, get_vector(px + 360, py + 33));
    sfText_setCharacterSize(temp->digit, 20);
    sfText_setString(temp->digit, get_str(val));
    sfText_setFont(temp->digit, font);
    sfText_setColor(temp->digit, sfBlack);
}

void init_slider_sprites(slider_t *temp, int px, int py, int val)
{
    temp->p_box = get_sprite("assets/pics/slider_component.png");
    temp->bar_empty = get_sprite("assets/pics/slider_component.png");
    temp->bar_filled = get_sprite("assets/pics/slider_component.png");
    temp->cursor->sprite = get_sprite("assets/pics/slider_component.png");

    sfSprite_setTextureRect(temp->p_box, get_intrect(44, 0, 28, 27));
    sfSprite_setTextureRect(temp->bar_empty, get_intrect(27, 0, 340, 16));
    sfSprite_setTextureRect(temp->bar_filled, get_intrect(0, 0, 345, 27));
    sfSprite_setTextureRect(temp->cursor->sprite, get_intrect(44, 28, 40, 24));

    sfSprite_setPosition(temp->p_box, get_vector(px + 350, py + 25));
    sfSprite_setPosition(temp->bar_empty, get_vector(px, py + 40));
    sfSprite_setPosition(temp->bar_filled, get_vector(px, py + 30));

    sfSprite_setScale(temp->bar_filled, get_vector(val / 100.0, 1));
    sfSprite_setScale(temp->p_box, get_vector(1.75, 1.5));
}

slider_t *initialize_slider(int px, int py, int val, char *name)
{
    slider_t *temp = malloc(sizeof(slider_t));

    temp->value = val;
    temp->coo = get_vector(px, py);
    temp->cursor = initialize_button(px + 150, py + 35, 40, 24);
    init_slider_sprites(temp, px, py, val);
    init_slider_name(temp, px, py, name);
    init_slider_digit(temp, px, py, val);

    write(1, "Slider initialisation -> ", 25);
    write(1, "Slider Successfully initialized\n", 32);
    return temp;
}
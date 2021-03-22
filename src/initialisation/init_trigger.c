/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** init_trigger
*/

#include "my_defender.h"

struct trigger *initialize_trigger(int px, int py, char *str)
{
    struct trigger *temp = malloc(sizeof(struct trigger));

    temp->coo = get_vector(1100, py);
    temp->size = get_vector(28, 28);
    temp->state = 0;

    temp->sprite = get_sprite("assets/pics/quad_btn.png");
    temp->check = get_sprite("assets/pics/quad_btn.png");
    temp->text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");

    sfSprite_setPosition(temp->sprite, temp->coo);
    sfSprite_setPosition(temp->check, temp->coo);
    sfSprite_setTextureRect(temp->sprite, get_intrect(0, 0, 28, 28));
    sfSprite_setTextureRect(temp->check, get_intrect(0, 112, 28, 28));

    sfText_setPosition(temp->text, get_vector(px, py));
    sfText_setCharacterSize(temp->text, 20);
    sfText_setString(temp->text, str);
    sfText_setFont(temp->text, font);

    write(1, "Trigger initialisation ->", 25);
    write(1, "Trigger Successfully initialized\n", 33);
    return temp;
}
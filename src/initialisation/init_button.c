/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** init_button
*/

#include "my_defender.h"

struct button *initialize_button(int px, int py, int sx, int sy)
{
    write(1, "Button initialisation -> ", 25);
    struct button *button_s = malloc(sizeof(struct button));

    button_s->coo = get_vector(px, py);
    button_s->size = get_vector(sx, sy);

    write(1, "Button Successfully initialized\n", 32);
    return (button_s);
}

void load_text_btn(struct button *button, int *trig, char *str)
{
    button->text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");

    sfText_setPosition(button->text, get_vector(button->coo.x + trig[0],
    button->coo.y + trig[1]));
    sfText_setCharacterSize(button->text, trig[2]);
    sfText_setString(button->text, str);
    sfText_setFont(button->text, font);
}
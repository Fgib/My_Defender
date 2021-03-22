/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_end_menu
*/

#include "my_defender.h"

void load_end_menu_bis(end_menu_t *temp)
{
    temp->transp = initialize_button(785, 530, 0, 0);
    temp->home = initialize_button(804, 542, 156, 156);
    temp->restart = initialize_button(804, 638, 156, 156);
    temp->transp->sprite = get_sprite("assets/pics/tri_button.png");
    temp->home->sprite = get_sprite("assets/pics/tri_button.png");
    temp->restart->sprite = get_sprite("assets/pics/tri_button.png");
}

end_menu_t *load_end_menu(void)
{
    end_menu_t *temp = malloc(sizeof(end_menu_t));
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");
    temp->background = get_sprite("assets/pics/fac_back.png");

    temp->condition = sfText_create();
    sfText_setFont(temp->condition, font);
    sfText_setCharacterSize(temp->condition, 60);
    load_end_menu_bis(temp);
    sfSprite_setTextureRect(temp->transp->sprite, get_intrect(0, 0, 156, 156));
    load_text_btn(temp->home, (int[4]){95, 22, 40}, "Home");
    load_text_btn(temp->restart, (int[4]){80, 22, 40}, "Restart");
    sfSprite_setScale(temp->transp->sprite, get_vector(2.25, 1.4));
    sfSprite_setScale(temp->home->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->restart->sprite, get_vector(2, 0.6));
    sfSprite_setPosition(temp->transp->sprite, temp->transp->coo);
    sfSprite_setPosition(temp->home->sprite, temp->home->coo);
    sfSprite_setPosition(temp->restart->sprite, temp->restart->coo);
    return temp;
}
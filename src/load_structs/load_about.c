/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_about
*/

#include "my_defender.h"

void load_about_menu_text(about_menu_t *temp)
{
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");

    temp->text = sfText_create();
    sfText_setPosition(temp->text, get_vector(810, 350));
    sfText_setFont(temp->text, font);
    sfText_setCharacterSize(temp->text, 15);
    sfText_setString(temp->text, "A game realised by Leo Brossard \nand"
    " Florian Gibault in first year \nat Epitech Lyon.\n\nThis project was "
    "completed using \nFactorio's spritesheets, thanks to \nKovarex "
    "team and Wube Software\n");
}

about_menu_t *load_about_menu(void)
{
    about_menu_t *temp = malloc(sizeof(about_menu_t));

    temp->transp = initialize_button(785, 280, 0, 0);
    temp->exit = initialize_button(804, 734, 312, 94);
    temp->transp->sprite = get_sprite("assets/pics/tri_button.png");
    temp->exit->sprite = get_sprite("assets/pics/tri_button.png");
    temp->background = get_sprite("assets/pics/fac_back.png");
    sfSprite_setTextureRect(temp->transp->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setScale(temp->transp->sprite, get_vector(2.25, 3.7));
    sfSprite_setScale(temp->exit->sprite, get_vector(2, 0.6));
    load_text_btn(temp->exit, (int[4]){80, 22, 40}, "Return");
    load_text_btn(temp->transp, (int[4]){20, 15, 40}, "About");
    sfSprite_setPosition(temp->transp->sprite, temp->transp->coo);
    sfSprite_setPosition(temp->exit->sprite, temp->exit->coo);
    load_about_menu_text(temp);
    return temp;
}
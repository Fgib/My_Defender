/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_pause
*/

#include "my_defender.h"

void load_pause_buttons(struct pause_menu *temp)
{
    load_text_btn(temp->transp, (int[4]){20, 15, 40}, "Pause");
    load_text_btn(temp->resume_b, (int[4]){76, 22, 40}, "Resume");
    load_text_btn(temp->restart_b, (int[4]){80, 22, 40}, "Restart");
    load_text_btn(temp->settings_b, (int[4]){72, 22, 40}, "Settings");
    load_text_btn(temp->menu_b, (int[4]){95, 22, 40}, "Home");
    load_text_btn(temp->exit_b, (int[4]){115, 22, 40}, "Exit");

    sfSprite_setScale(temp->resume_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->restart_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->settings_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->menu_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->exit_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->transp->sprite, get_vector(2.25, 3.7));

    sfSprite_setPosition(temp->resume_b->sprite, temp->resume_b->coo);
    sfSprite_setPosition(temp->restart_b->sprite, temp->restart_b->coo);
    sfSprite_setPosition(temp->settings_b->sprite, temp->settings_b->coo);
    sfSprite_setPosition(temp->menu_b->sprite, temp->menu_b->coo);
    sfSprite_setPosition(temp->transp->sprite, temp->transp->coo);
    sfSprite_setPosition(temp->exit_b->sprite, temp->exit_b->coo);
}

struct pause_menu *get_pause_s(void)
{
    struct pause_menu *temp = malloc(sizeof(struct pause_menu));

    temp->calc = get_sprite("assets/pics/pause_calc.png");
    temp->transp = initialize_button(785, 280, 0, 0);
    temp->resume_b = initialize_button(804, 350, 312, 94);
    temp->restart_b = initialize_button(804, 446, 312, 94);
    temp->settings_b = initialize_button(804, 542, 312, 94);
    temp->menu_b = initialize_button(804, 638, 312, 94);
    temp->exit_b = initialize_button(804, 734, 312, 94);
    temp->transp->sprite = get_sprite("assets/pics/tri_button.png");
    temp->resume_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->restart_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->settings_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->menu_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->exit_b->sprite = get_sprite("assets/pics/tri_button.png");
    sfSprite_setTextureRect(temp->transp->sprite, get_intrect(0, 0, 156, 156));
    load_pause_buttons(temp);

    return temp;
}
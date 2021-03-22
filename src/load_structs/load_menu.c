/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_menu
*/

#include "my_defender.h"

void setup_menu_btns(start_menu_t *temp)
{
    temp->transp = initialize_button(785, 280, 0, 0);
    temp->play_b = initialize_button(804, 350, 312, 94);
    temp->edit_b = initialize_button(804, 446, 312, 94);
    temp->sett_b = initialize_button(804, 542, 312, 94);
    temp->abot_b = initialize_button(804, 638, 312, 94);
    temp->exit_b = initialize_button(804, 734, 312, 94);

    temp->background = get_sprite("assets/pics/fac_back.png");
    temp->transp->sprite = get_sprite("assets/pics/tri_button.png");
    temp->play_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->edit_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->sett_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->abot_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->exit_b->sprite = get_sprite("assets/pics/tri_button.png");
    sfSprite_setTextureRect(temp->transp->sprite, get_intrect(0, 0, 156, 156));

    load_text_btn(temp->transp, (int[4]){20, 15, 40}, "My Defender");
    load_text_btn(temp->play_b, (int[4]){115, 22, 40}, "Play");
    load_text_btn(temp->edit_b, (int[4]){94, 22, 40}, "Editor");
    load_text_btn(temp->sett_b, (int[4]){72, 22, 40}, "Settings");
    load_text_btn(temp->abot_b, (int[4]){95, 22, 40}, "About");
    load_text_btn(temp->exit_b, (int[4]){115, 22, 40}, "Exit");
}

start_menu_t *get_menu_s(void)
{
    start_menu_t *temp = malloc(sizeof(start_menu_t));

    setup_menu_btns(temp);
    sfSprite_setScale(temp->transp->sprite, get_vector(2.25, 3.7));
    sfSprite_setScale(temp->play_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->edit_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->sett_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->abot_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->exit_b->sprite, get_vector(2, 0.6));

    sfSprite_setPosition(temp->transp->sprite, temp->transp->coo);
    sfSprite_setPosition(temp->play_b->sprite, temp->play_b->coo);
    sfSprite_setPosition(temp->edit_b->sprite, temp->edit_b->coo);
    sfSprite_setPosition(temp->sett_b->sprite, temp->sett_b->coo);
    sfSprite_setPosition(temp->abot_b->sprite, temp->abot_b->coo);
    sfSprite_setPosition(temp->exit_b->sprite, temp->exit_b->coo);
    temp->scenario_count = 0;
    temp->map_count = 0;

    return temp;
}
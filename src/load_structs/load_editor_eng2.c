/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** laod_editor_eng2
*/

#include "my_defender.h"

void load_editor_eng_5(editor_eng_t *temp)
{
    temp->tree1 = initialize_button(900, 1020, 60, 60);
    temp->tree1->sprite = get_sprite("assets/pics/tri_button.png");
    temp->tree1->icon = get_sprite("assets/trees/tree1.png");
    sfSprite_setTextureRect(temp->tree1->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setScale(temp->tree1->sprite, get_vector(0.38, 0.38));
    sfSprite_setScale(temp->tree1->icon, get_vector(0.25, 0.25));
    sfSprite_setPosition(temp->tree1->sprite, temp->tree1->coo);
    sfSprite_setPosition(temp->tree1->icon, get_vector(temp->tree1->coo.x
    + 15, temp->tree1->coo.y + 15));
    temp->tree2 = initialize_button(965, 1020, 60, 60);
    temp->tree2->sprite = get_sprite("assets/pics/tri_button.png");
    temp->tree2->icon = get_sprite("assets/trees/tree2.png");
    sfSprite_setTextureRect(temp->tree2->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setScale(temp->tree2->sprite, get_vector(0.38, 0.38));
    sfSprite_setScale(temp->tree2->icon, get_vector(0.25, 0.25));
    sfSprite_setPosition(temp->tree2->sprite, temp->tree2->coo);
    sfSprite_setPosition(temp->tree2->icon, get_vector(temp->tree2->coo.x
    + 15, temp->tree2->coo.y + 15));
}

void load_editor_eng_6(editor_eng_t *temp)
{
    temp->tree3 = initialize_button(1030, 1020, 60, 60);
    temp->tree3->sprite = get_sprite("assets/pics/tri_button.png");
    temp->tree3->icon = get_sprite("assets/trees/tree3.png");
    sfSprite_setTextureRect(temp->tree3->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setScale(temp->tree3->sprite, get_vector(0.38, 0.38));
    sfSprite_setScale(temp->tree3->icon, get_vector(0.25, 0.25));
    sfSprite_setPosition(temp->tree3->sprite, temp->tree3->coo);
    sfSprite_setPosition(temp->tree3->icon, get_vector(temp->tree3->coo.x
    + 15, temp->tree3->coo.y + 15));
    temp->useless = initialize_button(1785, 990, 0, 0);
    temp->useless->sprite = get_sprite("assets/pics/tri_button.png");
    sfSprite_setScale(temp->useless->sprite, get_vector(0.38, 0.38));
    sfSprite_setTextureRect(temp->useless->sprite, get_intrect(0, 0, 156,
    156));
    sfSprite_setPosition(temp->useless->sprite, temp->useless->coo);
    sfFont *font = sfFont_createFromFile("assets/font/fac_font.ttf");
    temp->layer_t = sfText_create();
    sfText_setPosition(temp->layer_t, get_vector(1805, 1005));
    sfText_setCharacterSize(temp->layer_t, 25);
    sfText_setFont(temp->layer_t, font);
}
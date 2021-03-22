/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_editor
*/

#include "my_defender.h"

void editor_menu_btn(editor_menu_t *temp)
{
    sfSprite_setScale(temp->home->sprite, get_vector(0.75, 0.4));
    sfSprite_setScale(temp->build->sprite, get_vector(0.75, 0.4));
    sfSprite_setScale(temp->transp1->sprite, get_vector(3.5, 6));
    sfSprite_setScale(temp->transp2->sprite, get_vector(6.41, 6));
    load_text_btn(temp->transp1, (int[4]){20, 15, 40}, "Maps");
    load_text_btn(temp->transp2, (int[4]){20, 15, 40}, "Details");
    load_text_btn(temp->home, (int[4]){32, 18, 20}, "Back");
    load_text_btn(temp->build, (int[4]){32, 18, 20}, "Edit");
    sfSprite_setPosition(temp->home->sprite, temp->home->coo);
    sfSprite_setPosition(temp->build->sprite, temp->build->coo);
    sfSprite_setPosition(temp->transp1->sprite, temp->transp1->coo);
    sfSprite_setPosition(temp->transp2->sprite, temp->transp2->coo);
    sfSprite_setTextureRect(temp->transp1->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setTextureRect(temp->transp2->sprite, get_intrect(0, 0, 156, 156));
}

void editor_menu_btn_list(editor_menu_t *temp, gen_t *prm)
{
    temp->maps_btn = malloc(sizeof(struct button) * prm->start_menu->map_count);
    for (int i = 0; i < prm->start_menu->map_count; i++) {
        temp->maps_btn[i] = initialize_button(200, 200 + 50 * i, 502, 47);
        temp->maps_btn[i]->sprite = get_sprite("assets/pics/tri_button.png");
        sfSprite_setScale(temp->maps_btn[i]->sprite, get_vector(3.22, 0.3));
        sfSprite_setPosition(temp->maps_btn[i]->sprite, temp->maps_btn[i]->coo);
        load_text_btn(temp->maps_btn[i], (int[4]){20 , 10, 20},
        str_truncate(prm->start_menu->maps[i].name, 35));
    }
}

editor_menu_t *get_edit_s(gen_t *prm)
{
    editor_menu_t *temp = malloc(sizeof(editor_menu_t));

    temp->select = -1;
    temp->background = get_sprite("assets/pics/fac_back.png");
    temp->home = initialize_button(394, 920, 117, 62);
    temp->build = initialize_button(1181, 920, 117, 62);
    temp->transp1 = initialize_button(180, 80, 0, 0);
    temp->transp2 = initialize_button(740, 80, 0, 0);
    temp->home->sprite = get_sprite("assets/pics/tri_button.png");
    temp->build->sprite = get_sprite("assets/pics/tri_button.png");
    temp->transp1->sprite = get_sprite("assets/pics/tri_button.png");
    temp->transp2->sprite = get_sprite("assets/pics/tri_button.png");
    editor_menu_btn(temp);
    editor_menu_btn_list(temp, prm);

    return temp;
}
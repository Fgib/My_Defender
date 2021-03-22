/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_selector
*/

#include "my_defender.h"

void get_selector_buttons(selec_menu_t *temp)
{
    temp->home->sprite = get_sprite("assets/pics/tri_button.png");
    temp->play->sprite = get_sprite("assets/pics/tri_button.png");
    temp->transp1->sprite = get_sprite("assets/pics/tri_button.png");
    temp->transp2->sprite = get_sprite("assets/pics/tri_button.png");
    sfSprite_setScale(temp->home->sprite, get_vector(0.75, 0.4));
    sfSprite_setScale(temp->play->sprite, get_vector(0.75, 0.4));
    sfSprite_setScale(temp->transp1->sprite, get_vector(3.5, 6));
    sfSprite_setScale(temp->transp2->sprite, get_vector(6.41, 6));
    load_text_btn(temp->transp1, (int[4]){20, 15, 40}, "Scenarios");
    load_text_btn(temp->transp2, (int[4]){20, 15, 40}, "Details");
    load_text_btn(temp->home, (int[4]){32, 18, 20}, "Back");
    load_text_btn(temp->play, (int[4]){32, 18, 20}, "Play");
    sfSprite_setPosition(temp->home->sprite, temp->home->coo);
    sfSprite_setPosition(temp->play->sprite, temp->play->coo);
    sfSprite_setPosition(temp->transp1->sprite, temp->transp1->coo);
    sfSprite_setPosition(temp->transp2->sprite, temp->transp2->coo);
    sfSprite_setTextureRect(temp->transp1->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setTextureRect(temp->transp2->sprite, get_intrect(0, 0, 156, 156));
}

void get_selector_scenarios_btn(selec_menu_t *temp, gen_t *prm)
{
    temp->scenarios_btn = malloc(sizeof(struct button) *
    prm->start_menu->scenario_count);
    for (int i = 0; i < prm->start_menu->scenario_count; i++) {
        temp->scenarios_btn[i] = initialize_button(200, 200 + 50 * i, 502, 47);
        temp->scenarios_btn[i]->sprite =
        get_sprite("assets/pics/tri_button.png");
        sfSprite_setScale(temp->scenarios_btn[i]->sprite,
        get_vector(3.22, 0.3));
        sfSprite_setPosition(temp->scenarios_btn[i]->sprite,
        temp->scenarios_btn[i]->coo);
        load_text_btn(temp->scenarios_btn[i], (int[4]){20 , 10, 20},
        str_truncate(prm->start_menu->scenarios[i].name, 35));
    }
}

void get_selector_texts(selec_menu_t *temp)
{

    temp->credits = sfText_create();
    temp->sce_name = sfText_create();
    temp->en_count = sfText_create();
    temp->wav_count = sfText_create();
    temp->difficulty = sfText_create();
    sfText_setPosition(temp->sce_name, get_vector(765, 150));
    sfText_setPosition(temp->credits, get_vector(765, 180));
    sfText_setPosition(temp->en_count, get_vector(765, 210));
    sfText_setPosition(temp->wav_count, get_vector(765, 240));
    sfText_setPosition(temp->difficulty, get_vector(765, 270));
    sfText_setCharacterSize(temp->credits, 25);
    sfText_setCharacterSize(temp->sce_name, 25);
    sfText_setCharacterSize(temp->en_count, 25);
    sfText_setCharacterSize(temp->wav_count, 25);
    sfText_setCharacterSize(temp->difficulty, 25);
}

void get_selector_texts_size(selec_menu_t *temp)
{
    sfFont *fac_font = sfFont_createFromFile("assets/font/fac_font.ttf");
    sfText_setFont(temp->credits, fac_font);
    sfText_setFont(temp->sce_name, fac_font);
    sfText_setFont(temp->en_count, fac_font);
    sfText_setFont(temp->wav_count, fac_font);
    sfText_setFont(temp->difficulty, fac_font);
}

selec_menu_t *get_selector(gen_t *prm)
{
    selec_menu_t *temp = malloc(sizeof(selec_menu_t));

    temp->select = -1;
    temp->background = get_sprite("assets/pics/fac_back.png");
    temp->home = initialize_button(394, 920, 117, 62);
    temp->play = initialize_button(1181, 920, 117, 62);
    temp->transp1 = initialize_button(180, 80, 0, 0);
    temp->transp2 = initialize_button(740, 80, 0, 0);
    get_selector_buttons(temp);
    get_selector_scenarios_btn(temp, prm);
    get_selector_texts(temp);
    get_selector_texts_size(temp);


    sfTexture *sol = sfTexture_createFromFile("assets/pics/dirt.png", NULL);
    sfTexture_setRepeated(sol, sfTrue);
    temp->map_back = sfSprite_create();
    sfSprite_setTexture(temp->map_back, sol, sfFalse);
    sfSprite_setTextureRect(temp->map_back,
    get_intrect(0, 0, 1920 / 2, 1080 / 2));
    sfSprite_setPosition(temp->map_back, get_vector(755, 335));
    return temp;
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_settings
*/

#include "my_defender.h"

void setup_sub_settings(setti_menu_t *temp)
{
    temp->main_volume = initialize_slider(789, 350, 50, "Main Volume");
    temp->music = initialize_slider(789, 430, 50, "Musics");
    temp->effects = initialize_slider(789, 510, 50, "Effects");
    temp->ennemis = initialize_slider(789, 590, 50, "Enemies");
    temp->alerts = initialize_slider(789, 670, 50, "Alerts");
    temp->wind = initialize_slider(789, 750, 50, "Wind");

    temp->vsync = initialize_trigger(804, 350, "Vsync");
    temp->focus = initialize_trigger(804, 420, "Pause on focus lost");
    temp->high_res = initialize_trigger(804, 490, "High res textures");
    temp->luminosity = initialize_slider(789, 590, 50, "Luminosity");
    temp->contrast = initialize_slider(789, 670, 50, "Contrast");
    temp->saturation = initialize_slider(789, 750, 50, "Saturation");
}

void setup_settings_btns(setti_menu_t *temp)
{
    temp->transp = initialize_button(385, 280, 0, 0);
    temp->transp2 = initialize_button(750, 234, 0, 0);
    temp->graphic_b = initialize_button(404, 350, 312, 94);
    temp->binding_b = initialize_button(404, 446, 312, 94);
    temp->sounds_b = initialize_button(404, 542, 312, 94);
    temp->gui_b = initialize_button(404, 638, 312, 94);
    temp->menu_b = initialize_button(404, 734, 312, 94);

    temp->background = get_sprite("assets/pics/fac_back.png");
    temp->transp->sprite = get_sprite("assets/pics/tri_button.png");
    temp->transp2->sprite = get_sprite("assets/pics/tri_button.png");
    temp->graphic_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->binding_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->sounds_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->gui_b->sprite = get_sprite("assets/pics/tri_button.png");
    temp->menu_b->sprite = get_sprite("assets/pics/tri_button.png");
    sfSprite_setTextureRect(temp->transp->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setTextureRect(temp->transp2->sprite, get_intrect(0, 0, 156, 156));
}

void setup_settings_btns_bis(setti_menu_t *temp)
{
    load_text_btn(temp->transp, (int[4]){20, 15, 40}, "Settings");
    load_text_btn(temp->transp2, (int[4]){20, 15, 40}, "Sub-Settings");
    load_text_btn(temp->graphic_b, (int[4]){20, 15, 40}, "Graphism");
    load_text_btn(temp->binding_b, (int[4]){20, 15, 40}, "Key-Binding");
    load_text_btn(temp->sounds_b, (int[4]){20, 15, 40}, "Sounds");
    load_text_btn(temp->gui_b, (int[4]){20, 15, 40}, "Interface");
    load_text_btn(temp->menu_b, (int[4]){20, 15, 40}, "Home");

    sfSprite_setScale(temp->transp->sprite, get_vector(2.25, 3.7));
    sfSprite_setScale(temp->transp2->sprite, get_vector(3, 4));
    sfSprite_setScale(temp->graphic_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->binding_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->sounds_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->gui_b->sprite, get_vector(2, 0.6));
    sfSprite_setScale(temp->menu_b->sprite, get_vector(2, 0.6));
}

void load_settings_keymap(setti_menu_t *temp)
{
    temp->go_up = initialize_button(1080, 350, 60, 60);
    temp->go_right = initialize_button(1080, 450, 60, 60);
    temp->go_down = initialize_button(1080, 550, 60, 60);
    temp->go_left = initialize_button(1080, 650, 60, 60);
    temp->go_up->sprite = get_sprite("assets/pics/tri_button.png");
    temp->go_right->sprite = get_sprite("assets/pics/tri_button.png");
    temp->go_down->sprite = get_sprite("assets/pics/tri_button.png");
    temp->go_left->sprite = get_sprite("assets/pics/tri_button.png");
    sfSprite_setPosition(temp->go_up->sprite, temp->go_up->coo);
    sfSprite_setPosition(temp->go_right->sprite, temp->go_right->coo);
    sfSprite_setPosition(temp->go_down->sprite, temp->go_down->coo);
    sfSprite_setPosition(temp->go_left->sprite, temp->go_left->coo);

    load_text_settings_keymap_b(temp);
    load_text_settings_keymap_bis(temp);
}

setti_menu_t *get_sett_s(void)
{
    setti_menu_t *temp = malloc(sizeof(setti_menu_t));

    temp->set_step = SET_HOME;
    temp->mapselect = 0;
    setup_sub_settings(temp);
    setup_settings_btns(temp);
    load_settings_keymap(temp);
    setup_settings_btns_bis(temp);
    sfSprite_setPosition(temp->transp->sprite, temp->transp->coo);
    sfSprite_setPosition(temp->transp2->sprite, temp->transp2->coo);
    sfSprite_setPosition(temp->graphic_b->sprite, temp->graphic_b->coo);
    sfSprite_setPosition(temp->binding_b->sprite, temp->binding_b->coo);
    sfSprite_setPosition(temp->sounds_b->sprite, temp->sounds_b->coo);
    sfSprite_setPosition(temp->gui_b->sprite, temp->gui_b->coo);
    sfSprite_setPosition(temp->menu_b->sprite, temp->menu_b->coo);

    return temp;
}
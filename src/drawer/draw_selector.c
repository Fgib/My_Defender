/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_selector
*/

#include "my_defender.h"

void draw_scenario_info(gen_t *prm)
{
    sfRenderWindow_drawSprite(prm->window,
    prm->selec_menu->transp2->sprite, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->selec_menu->transp2->text, NULL);
    sfRenderWindow_drawSprite(prm->window,
    prm->selec_menu->play->sprite, NULL);
    sfRenderWindow_drawText(prm->window,
    prm->selec_menu->play->text, NULL);
    sfText_setString(prm->selec_menu->credits,
    str_add("Golds : ", get_str(prm->start_menu->scenarios[
    prm->selec_menu->select].detail.credit)));
    sfText_setString(prm->selec_menu->sce_name,
    str_add("Name : ", prm->start_menu->scenarios[
    prm->selec_menu->select].name));
    sfText_setString(prm->selec_menu->en_count,
    str_add("Ennemies diversity : ", get_str(prm->start_menu->scenarios[
    prm->selec_menu->select].detail.ennemy_count)));
    sfText_setString(prm->selec_menu->wav_count,
    str_add("Number of waves : ", get_str(prm->start_menu->scenarios[
    prm->selec_menu->select].detail.wave_count)));
}

void draw_scenarios_list(gen_t *prm)
{
    for (int i = 0; i < prm->start_menu->scenario_count; i++) {
        sfRenderWindow_drawSprite(prm->window,
        prm->selec_menu->scenarios_btn[i]->sprite, NULL);
        sfRenderWindow_drawText(prm->window,
        prm->selec_menu->scenarios_btn[i]->text, NULL);
    }
}

void draw_selector(gen_t *prm)
{
    sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
    sfRenderWindow_drawSprite(prm->window, prm->selec_menu->background, NULL);
    sfRenderWindow_drawSprite(prm->window, prm->selec_menu->transp1->sprite,
    NULL);
    sfRenderWindow_drawSprite(prm->window, prm->selec_menu->home->sprite, NULL);
    sfRenderWindow_drawText(prm->window, prm->selec_menu->transp1->text, NULL);
    sfRenderWindow_drawText(prm->window, prm->selec_menu->home->text, NULL);
    draw_scenarios_list(prm);
    if (prm->selec_menu->select != -1) {
        draw_scenario_info(prm);
        sfRenderWindow_drawText(prm->window, prm->selec_menu->credits, NULL);
        sfRenderWindow_drawText(prm->window, prm->selec_menu->sce_name, NULL);
        sfRenderWindow_drawText(prm->window, prm->selec_menu->en_count, NULL);
        sfRenderWindow_drawText(prm->window, prm->selec_menu->wav_count, NULL);

        sfRenderWindow_drawSprite(prm->window, prm->selec_menu->map_back, NULL);
        map_mini_printer(prm, prm->selec_menu->select);
    }
}
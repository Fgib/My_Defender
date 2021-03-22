/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** draw_game
*/

#include "my_defender.h"

void draw_turrets_ui(game_t *eng, sfRenderWindow *window)
{
    sfVector2f temp = sfSprite_getScale(eng->transp->sprite);

    NVECTOR(eng->transp->size, temp.x * 156, temp.y * 156)
    sfSprite_setScale(eng->transp->sprite,
    get_vector(eng->turrets_dic_count, 1));
    sfSprite_setPosition(eng->transp->sprite,
    get_vector(960 - 156 * eng->turrets_dic_count / 2, 950));
    eng->transp->coo = sfSprite_getPosition(eng->transp->sprite);
    sfRenderWindow_drawSprite(window, eng->transp->sprite, NULL);
    for (int i = 0; i < eng->turrets_dic_count; i++) {
        sfSprite_setPosition(eng->turrets_btn[i]->sprite,
        get_vector(960 - 155 * eng->turrets_dic_count / 2 + 160 * i, 960));
        eng->turrets_btn[i]->coo =
        sfSprite_getPosition(eng->turrets_btn[i]->sprite);
        sfRenderWindow_drawSprite(window, eng->turrets_btn[i]->sprite, NULL);
        sfSprite_setPosition(eng->turrets_btn[i]->icon,
        get_vector(eng->turrets_btn[i]->coo.x + 30,
        eng->turrets_btn[i]->coo.y + 20));
        sfRenderWindow_drawSprite(window, eng->turrets_btn[i]->icon, NULL);
    }
}

void cursor_state2(game_t *ge, int result)
{
    if (result == -2){
        sfSprite_setTextureRect(ge->cursor, get_intrect(0, 0, 30, 30));
        sfText_setString(ge->cursor_info, "Not enough money");
        sfText_setPosition(ge->cursor_info,
        get_vector(ge->last_mouse.x * 30 - 30, ge->last_mouse.y * 30 - 10));
    }
    if (result == -3){
        sfSprite_setTextureRect(ge->cursor, get_intrect(0, 0, 30, 30));
        sfText_setString(ge->cursor_info, "Too far");
        sfText_setPosition(ge->cursor_info,
        get_vector(ge->last_mouse.x * 30 - 5, ge->last_mouse.y * 30 - 10));
    }
}

void cursor_state(game_t *ge)
{
    int result = can_buy_turret(ge, 0, ge->last_mouse);

    if (result > 0) {
        sfSprite_setTextureRect(ge->cursor, get_intrect(0, 60, 30, 30));
        sfText_setString(ge->cursor_info, "");
    }
    if (result == -1) {
        sfSprite_setTextureRect(ge->cursor, get_intrect(0, 0, 30, 30));
        sfText_setString(ge->cursor_info, "Invalid place");
        sfText_setPosition(ge->cursor_info,
        get_vector(ge->last_mouse.x * 30 - 15, ge->last_mouse.y * 30 - 10));
    }
    cursor_state2(ge, result);
}

void draw_life_bar(gen_t *prm)
{
    double value = prm->game_eng->life / prm->game_eng->max_life;
    sfSprite_setPosition(prm->game_eng->health.frame,
    prm->game_eng->health.coo);
    sfSprite_setPosition(prm->game_eng->health.bar,
    get_vector(prm->game_eng->health.coo.x + 3, prm->game_eng->health.coo.y));
    sfRenderWindow_drawSprite(prm->window, prm->game_eng->health.frame, NULL);
    sfSprite_setScale(prm->game_eng->health.bar, get_vector(value, 1));
    sfRenderWindow_drawSprite(prm->window, prm->game_eng->health.bar, NULL);
}

void draw_game(gen_t *prm)
{
    sfRenderWindow_setView(prm->window, prm->camera);
    draw_back(prm, prm->game_eng, prm->window);
    sfRenderWindow_setView(prm->window, prm->player);
    sfRenderWindow_drawSprite(prm->window, prm->game_eng->player->player_sheet,
    NULL);
    sfRenderWindow_setView(prm->window, prm->interface);
    draw_interface(prm, prm->game_eng, prm->window);
}
/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** draw_game2
*/

#include "my_defender.h"

void draw_back(gen_t *prm, game_t *eng, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, eng->background, NULL);
    map_printer(prm);
    ennemies_printer(prm);
    turrets_printer(prm);
    if (eng->igs == NORMAL) {
        sfSprite_setPosition(eng->cursor, get_vector(eng->last_mouse.x * 30,
        eng->last_mouse.y * 30));
        if (eng->turret_select != -1)
            cursor_state(eng);
        else
            sfSprite_setTextureRect(eng->cursor, get_intrect(0, 30, 30, 30));
        sfRenderWindow_drawSprite(win, eng->cursor, NULL);
        sfRenderWindow_drawText(win, eng->cursor_info, NULL);
    }
    sfView_setCenter(prm->camera, eng->player->coo);
}

void draw_interface2(game_t *eng, sfRenderWindow *win)
{
    sfText_setString(eng->turret_info.id,
    str_add("Turret ID :\t", get_str(eng->tmp_turret->id)));
    sfText_setString(eng->turret_info.level,
    str_add("Level :\t", get_str(eng->tmp_turret->level)));
    sfText_setString(eng->turret_info.damage,
    str_add("Damage :\t", get_str(eng->tmp_turret->damage)));
    sfText_setString(eng->turret_info.fire_rate,
    str_add("Fire rate :\t", get_str(eng->tmp_turret->fire_rate)));
    sfText_setString(eng->turret_info.range,
    str_add("Range :\t", get_str(eng->tmp_turret->range)));
    sfRenderWindow_drawText(win, eng->turret_info.id, NULL);
    sfRenderWindow_drawText(win, eng->turret_info.level, NULL);
    sfRenderWindow_drawText(win, eng->turret_info.damage, NULL);
    sfRenderWindow_drawText(win, eng->turret_info.fire_rate, NULL);
    sfRenderWindow_drawText(win, eng->turret_info.range, NULL);
}

void draw_interface(gen_t *prm, game_t *eng, sfRenderWindow *win)
{
    draw_life_bar(prm);
    sfRenderWindow_drawSprite(win, eng->transp_fric, NULL);
    sfText_setString(eng->credit_text, get_str(eng->credit));
    sfRenderWindow_drawText(win, eng->credit_text, NULL);
    sfText_setString(eng->gear_text, get_str(eng->gear));
    sfRenderWindow_drawText(win, eng->gear_text, NULL);
    sfRenderWindow_drawSprite(win, eng->gear_s, NULL);
    sfRenderWindow_drawSprite(win, eng->credit_s, NULL);
    draw_turrets_ui(eng, win);

    if (eng->igs == INFORM) {
        sfRenderWindow_setMouseCursorVisible(win, sfTrue);
        sfRenderWindow_drawSprite(win, eng->turret_info.background, NULL);
        sfRenderWindow_drawSprite(win, eng->turret_info.sell->sprite, NULL);
        sfRenderWindow_drawText(win, eng->turret_info.sell->text, NULL);
        sfRenderWindow_drawSprite(win, eng->turret_info.close->sprite, NULL);
        sfRenderWindow_drawText(win, eng->turret_info.close->text, NULL);
        sfRenderWindow_drawSprite(win, eng->turret_info.upgrade->sprite, NULL);
        sfRenderWindow_drawText(win, eng->turret_info.upgrade->text, NULL);
        draw_interface2(eng, win);
    }
}
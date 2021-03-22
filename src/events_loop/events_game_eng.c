/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** events_game_eng
*/

#include "my_defender.h"

void turret_informator(gen_t *prm)
{
    turrets_t *tmp = get_turret_by_pos(prm->game_eng,

    prm->game_eng->last_mouse);
    if (prm->event.type == sfEvtMouseButtonPressed && tmp != NULL) {
        prm->game_eng->tmp_turret = tmp;
        prm->game_eng->igs = INFORM;
    }
}

void informator_menu(gen_t *prm)
{
    if (triforce(prm->event, prm->game_eng->turret_info.close,
        prm->sound->btn_press) || (prm->event.type == sfEvtKeyPressed &&
        prm->event.key.code == sfKeyEscape))
        prm->game_eng->igs = NORMAL;
    if (triforce(prm->event, prm->game_eng->turret_info.upgrade,
    prm->sound->btn_press)) {
        if (can_upgrade_turret(prm->game_eng) > 0)
            upgrade_turret(prm->game_eng, 1);
    }
    if (triforce(prm->event, prm->game_eng->turret_info.sell,
    prm->sound->btn_press)) {
        delete_turret_by_id(prm->game_eng, prm->game_eng->tmp_turret->id);
        prm->game_eng->credit += prm->game_eng->tmp_turret->price * 0.8;
        prm->game_eng->igs = NORMAL;
    }
}

void turret_selector(gen_t *prm)
{
    if (prm->keys.mouse == 1 && prm->game_eng->turret_select != -1) {
        buy_turret(prm, prm->game_eng->turret_select,
        prm->game_eng->last_mouse);
    }
    if (click_is_up(prm->event, prm->game_eng->transp))
        sfRenderWindow_setMouseCursorVisible(prm->window, sfTrue);
    else
        sfRenderWindow_setMouseCursorVisible(prm->window, sfFalse);
    for (int i = 0; i < prm->game_eng->turrets_dic_count; i++) {
        if (triforce(prm->event, prm->game_eng->turrets_btn[i],
        prm->sound->btn_press)) {
            prm->game_eng->turret_select = i;
        }
    }
}

int has_win(game_t *eng)
{
    if (exec_wave(eng))
        return 0;
    for (int i = 0; i < eng->ennemies_count; ++i)
        if (eng->ennemies[i].health > 0)
            return 0;
    return 1;
}

void game_eng_event(gen_t *prm)
{
    if (prm->event.type == sfEvtKeyPressed && prm->game_eng->igs == NORMAL) {
        if (prm->event.key.code == sfKeyEscape &&
            prm->game_eng->turret_select == -1)
            prm->game_step = PAUSE;
        if (prm->event.key.code == sfKeyEscape &&
            prm->game_eng->turret_select != -1)
            prm->game_eng->turret_select = -1;
        if (prm->event.key.code == sfKeySpace)
            prm->game_eng->trig = 1;
        if (prm->event.key.code == sfKeyV)
            create_ennemy(prm->game_eng, 3);
    }
    eng_bis(prm);
}
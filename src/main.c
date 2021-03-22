/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "my_defender.h"

void sound_destroyer(gen_t *prm)
{
    sfMusic_destroy(prm->sound->wind);
    sfMusic_destroy(prm->sound->intro);
    sfMusic_destroy(prm->sound->alert);
    sfMusic_destroy(prm->sound->siren);
    sfMusic_destroy(prm->sound->ambiance);
    sfMusic_destroy(prm->sound->game_win);
    sfMusic_destroy(prm->sound->game_over);
    sfSoundBuffer_destroy(prm->sound->b_laser);
    sfSoundBuffer_destroy(prm->sound->b_wav);
    sfSoundBuffer_destroy(prm->sound->b_btn);
    sfSoundBuffer_destroy(prm->sound->b_explo);
    sfSoundBuffer_destroy(prm->sound->b_imp);
    sfSoundBuffer_destroy(prm->sound->b_death);
    sfSound_destroy(prm->sound->laser);
    sfSound_destroy(prm->sound->wave_end);
    sfSound_destroy(prm->sound->btn_press);
    sfSound_destroy(prm->sound->explosion);
    sfSound_destroy(prm->sound->impossible);
    sfSound_destroy(prm->sound->bitter_death);
}

void dispose(gen_t *prm)
{
    write(1, "Free begining\n", 14);
    sound_destroyer(prm);
    write(1, "Sounds freed\n", 13);
    sfRenderWindow_destroy(prm->window);
    free(prm);
    write(1, "Successfully free\n", 18);
}

void refresh_window(gen_t *prm)
{
    sfRenderWindow_clear(prm->window, sfBlack);
    window_update(prm);
    sfRenderWindow_display(prm->window);
}

void game_calculation(gen_t *prm)
{
    check_ennemies_goal(prm->game_eng);
    ennemies_mover(prm);
    spawn_ennemies(prm);
    ennemies_animation(prm);
    for (int i = 0; i < prm->game_eng->turrets_count; i++) {
        fire_ennemy(prm->game_eng, &prm->game_eng->turrets[i], prm->sound);
    }
    player_mover(prm);
    player_animation(prm);
}

int main(void)
{
    gen_t *prm = get_struct_settings();

    sfMusic_play(prm->sound->intro);
    sfMusic_play(prm->sound->ambiance);
    sfRenderWindow_setFramerateLimit(prm->window, 60);
    while (sfRenderWindow_isOpen(prm->window) && prm->game_step != OUT) {
        while (sfRenderWindow_pollEvent(prm->window, &prm->event)) {
            manage_events(prm);
        }
        if (sfClock_getElapsedTime(prm->animation_clock).microseconds >
        1000000 / 44 && prm->game_step == GAME) {
            game_calculation(prm);
        }
        sound_level(prm);
        refresh_window(prm);
    }
    dispose(prm);
    return 0;
}
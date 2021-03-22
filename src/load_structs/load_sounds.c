/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_sounds
*/

#include "my_defender.h"

void load_musics(sound_t *temp)
{
    temp->wind = sfMusic_createFromFile("assets/sound/wind.ogg");
    temp->intro = sfMusic_createFromFile("assets/sound/intro.ogg");
    temp->alert = sfMusic_createFromFile("assets/sound/alert.ogg");
    temp->siren = sfMusic_createFromFile("assets/sound/siren.ogg");
    temp->ambiance = sfMusic_createFromFile("assets/sound/music.ogg");
    temp->game_win = sfMusic_createFromFile("assets/sound/game-won.ogg");
    temp->game_over = sfMusic_createFromFile("assets/sound/game-lost.ogg");
    sfMusic_setLoop(temp->wind, sfTrue);
    sfMusic_setLoop(temp->ambiance, sfTrue);
    sfMusic_setLoop(temp->alert, sfTrue);
    sfMusic_setLoop(temp->siren, sfTrue);
}

void sounds_buffering(sound_t *temp)
{
    temp->b_laser = sfSoundBuffer_createFromFile("assets/sound/laser.ogg");
    temp->b_wav = sfSoundBuffer_createFromFile("assets/sound/wave_end.ogg");
    temp->b_btn = sfSoundBuffer_createFromFile("assets/sound/btn_song.ogg");
    temp->b_explo = sfSoundBuffer_createFromFile("assets/sound/explosion.ogg");
    temp->b_imp = sfSoundBuffer_createFromFile("assets/sound/impossible.ogg");
    temp->b_death =
    sfSoundBuffer_createFromFile("assets/sound/biter_death.ogg");

    sfSound_setBuffer(temp->laser, temp->b_laser);
    sfSound_setBuffer(temp->wave_end, temp->b_wav);
    sfSound_setBuffer(temp->btn_press, temp->b_btn);
    sfSound_setBuffer(temp->explosion, temp->b_explo);
    sfSound_setBuffer(temp->impossible, temp->b_imp);
    sfSound_setBuffer(temp->bitter_death, temp->b_death);
}

sound_t *load_sounds(void)
{
    sound_t *temp = malloc(sizeof(sound_t));

    temp->laser = sfSound_create();
    temp->wave_end = sfSound_create();
    temp->btn_press = sfSound_create();
    temp->explosion = sfSound_create();
    temp->impossible = sfSound_create();
    temp->bitter_death = sfSound_create();
    sounds_buffering(temp);
    load_musics(temp);

    return temp;
}
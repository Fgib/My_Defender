/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** init_window
*/

#include "my_defender.h"

sfRenderWindow *window_creator(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, \
    "My_defender", sfTitlebar | sfClose, NULL);
    return (window);
}
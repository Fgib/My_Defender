/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** init_player
*/

#include "my_defender.h"

struct player *initialize_player(void)
{
    write(1, "Player initialisation -> ", 25);
    struct player *player_s = malloc(sizeof(struct player));

    if (player_s == NULL)
        write(1, "Player initialisation failed\n", 29);
    player_s->coo = get_vector(960, 540);
    player_s->skin_id = 0;
    player_s->dir = 1;

    write(1, "Player Successfully initialized\n", 32);
    return (player_s);
}
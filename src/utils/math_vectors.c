/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** vectors
*/

#include "my_defender.h"

vec3_t get_vector3(int x, int y, int z)
{
    vec3_t vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;
    return vector;
}

pos_t get_vec2(int x, int y)
{
    pos_t pos;

    pos.x = x;
    pos.y = y;
    return pos;
}
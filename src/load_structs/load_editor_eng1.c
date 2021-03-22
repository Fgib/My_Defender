/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_editor_eng
*/

#include "my_defender.h"
void load_editor_eng_5(editor_eng_t *temp);
void load_editor_eng_6(editor_eng_t *temp);


void load_editor_eng_1(editor_eng_t *temp)
{
    temp->path = initialize_button(1850, 300, 60, 60);
    temp->path->sprite = get_sprite("assets/pics/tri_button.png");
    temp->path->icon = get_sprite("assets/pics/concrete.png");
    sfSprite_setTextureRect(temp->path->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setScale(temp->path->sprite, get_vector(0.38, 0.38));
    sfSprite_setPosition(temp->path->sprite, temp->path->coo);
    sfSprite_setPosition(temp->path->icon, get_vector(temp->path->coo.x + 15,
    temp->path->coo.y + 15));
    temp->water = initialize_button(835, 1020, 60, 60);
    temp->water->sprite = get_sprite("assets/pics/tri_button.png");
    temp->water->icon = get_sprite("assets/pics/water.png");
    sfSprite_setTextureRect(temp->water->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setScale(temp->water->sprite, get_vector(0.38, 0.38));
    sfSprite_setPosition(temp->water->sprite, temp->water->coo);
    sfSprite_setPosition(temp->water->icon, get_vector(temp->water->coo.x + 15,
    temp->water->coo.y + 15));
    temp->start = initialize_button(1850, 365, 60, 60);
}

void load_editor_eng_2(editor_eng_t *temp)
{
    temp->start->sprite = get_sprite("assets/pics/tri_button.png");
    temp->start->icon = get_sprite("assets/pics/hive.png");
    sfSprite_setTextureRect(temp->start->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setScale(temp->start->sprite, get_vector(0.38, 0.38));
    sfSprite_setScale(temp->start->icon, get_vector(0.6, 0.6));
    sfSprite_setPosition(temp->start->sprite, temp->start->coo);
    sfSprite_setPosition(temp->start->icon, get_vector(temp->start->coo.x + 5,
    temp->start->coo.y + 15));
    temp->end = initialize_button(1850, 430, 60, 60);
    temp->end->sprite = get_sprite("assets/pics/tri_button.png");
    temp->end->icon = get_sprite("assets/pics/reac.png");
    sfSprite_setTextureRect(temp->end->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setScale(temp->end->sprite, get_vector(0.38, 0.38));
    sfSprite_setScale(temp->end->icon, get_vector(0.45, 0.45));
    sfSprite_setPosition(temp->end->sprite, temp->end->coo);
    sfSprite_setPosition(temp->end->icon, get_vector(temp->end->coo.x + 8,
    temp->end->coo.y + 10));
    temp->erase = initialize_button(1850, 495, 60, 60);
}

void load_editor_eng_3(editor_eng_t *temp)
{
    temp->erase->sprite = get_sprite("assets/pics/tri_button.png");
    temp->erase->icon = get_sprite("assets/pics/tri_cursor.png");
    sfSprite_setTextureRect(temp->erase->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setTextureRect(temp->erase->icon, get_intrect(0, 0, 30, 30));
    sfSprite_setScale(temp->erase->sprite, get_vector(0.38, 0.38));
    sfSprite_setPosition(temp->erase->sprite, temp->erase->coo);
    sfSprite_setPosition(temp->erase->icon, get_vector(temp->erase->coo.x + 15,
    temp->erase->coo.y + 15));

    temp->layer_up = initialize_button(1850, 960, 60, 60);
    temp->layer_up->sprite = get_sprite("assets/pics/tri_button.png");
    temp->layer_up->icon = get_sprite("assets/pics/arrow.png");
    sfSprite_setTextureRect(temp->layer_up->sprite, get_intrect(0, 0, 156,
    156));
    sfSprite_setTextureRect(temp->layer_up->icon, get_intrect(0, 0, 32, 24));
    sfSprite_setScale(temp->layer_up->sprite, get_vector(0.38, 0.38));
    sfSprite_setPosition(temp->layer_up->sprite, temp->layer_up->coo);
    sfSprite_setPosition(temp->layer_up->icon, get_vector(temp->layer_up->coo.x
    + 15, temp->layer_up->coo.y + 15));
}

void load_editor_eng_4(editor_eng_t *temp)
{
    temp->layer_down = initialize_button(1850, 1020, 60, 60);
    temp->layer_down->sprite = get_sprite("assets/pics/tri_button.png");
    temp->layer_down->icon = get_sprite("assets/pics/arrow.png");
    sfSprite_setTextureRect(temp->layer_down->sprite, get_intrect(0, 0, 156,
    156));
    sfSprite_setTextureRect(temp->layer_down->icon, get_intrect(25, 0, 32, 24));
    sfSprite_setScale(temp->layer_down->sprite, get_vector(0.38, 0.38));
    sfSprite_setPosition(temp->layer_down->sprite, temp->layer_down->coo);
    sfSprite_setPosition(temp->layer_down->icon,
    get_vector(temp->layer_down->coo.x + 15, temp->layer_down->coo.y + 15));
    temp->hitbox = initialize_button(1850, 560, 60, 60);
    temp->hitbox->sprite = get_sprite("assets/pics/tri_button.png");
    temp->hitbox->icon = get_sprite("assets/pics/barrier.png");
    sfSprite_setTextureRect(temp->hitbox->sprite, get_intrect(0, 0, 156, 156));
    sfSprite_setScale(temp->hitbox->sprite, get_vector(0.38, 0.38));
    sfSprite_setPosition(temp->hitbox->sprite, temp->hitbox->coo);
    sfSprite_setPosition(temp->hitbox->icon, get_vector(temp->hitbox->coo.x
    + 15, temp->hitbox->coo.y + 15));
}

editor_eng_t *load_editor_eng(void)
{
    editor_eng_t *temp = malloc(sizeof(editor_eng_t));

    temp->layer = 0;
    temp->select = 0;
    sfTexture *sol = sfTexture_createFromFile("assets/pics/dirt.png", NULL);
    sfTexture_setRepeated(sol, sfTrue);
    temp->background = sfSprite_create();
    sfSprite_setTexture(temp->background, sol, sfFalse);
    sfSprite_setTextureRect(temp->background,
    get_intrect(-1920, -1080, 1920 * 3, 1080 * 3));
    sfSprite_setOrigin(temp->background, get_vector(1920, 1080));

    temp->cursor = get_sprite("assets/pics/tri_cursor.png");
    sfSprite_setTextureRect(temp->cursor, get_intrect(0, 60, 30, 30));
    load_editor_eng_1(temp);
    load_editor_eng_2(temp);
    load_editor_eng_3(temp);
    load_editor_eng_4(temp);
    load_editor_eng_5(temp);
    load_editor_eng_6(temp);
    return temp;
}
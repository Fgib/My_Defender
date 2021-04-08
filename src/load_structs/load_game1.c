/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** load_game
*/

#include "my_defender.h"
void setup_money_ui(game_t *temp);
void setup_turret_bar(game_t *temp);

void setup_background(game_t *temp)
{
    sfTexture *sol = sfTexture_createFromFile("assets/pics/dirt.png", NULL);
    sfTexture_setRepeated(sol, sfTrue);
    temp->background = sfSprite_create();
    sfSprite_setTexture(temp->background, sol, sfFalse);
    sfSprite_setTextureRect(temp->background,
    get_intrect(-1920, -1080, 1920 * 3, 1080 * 3));
    sfSprite_setOrigin(temp->background, get_vector(1920, 1080));
}

void setup_bar(game_t *temp)
{
    temp->health.texture = sfTexture_createFromFile("assets/pics/health_bar.png"
    , NULL);
    temp->health.coo = get_vector(480, 15);
    temp->cursor = get_sprite("assets/pics/tri_cursor.png");
    temp->health.frame = sfSprite_create();
    temp->health.bar = sfSprite_create();
    sfSprite_setTextureRect(temp->cursor, get_intrect(0, 60, 30, 30));
    sfSprite_setTexture(temp->health.frame, temp->health.texture, sfTrue);
    sfSprite_setTextureRect(temp->health.frame, get_intrect(0, 0, 960, 15));
    sfSprite_setTexture(temp->health.bar, temp->health.texture, sfTrue);
    sfSprite_setTextureRect(temp->health.bar, get_intrect(15, 0, 960, 15));
}

void setup_values(game_t *temp)
{
    temp->zoom = 0;
    temp->trig = 0;
    temp->gear = 0;
    temp->life = 10000;
    temp->turret_id = 0;
    temp->ennemy_id = 0;
    temp->wave_status = 1;
    temp->max_life = 10000;
    temp->turrets_count = 0;
    temp->ennemies_count = 0;
    temp->turret_select = -1;
    temp->waves.wave_count = 0;
    temp->turrets_dic_count = 0;
    temp->ennemies_dic_count = 0;
}

void setup_game_texts(game_t *temp)
{
    sfFont *fac_font = sfFont_createFromFile("assets/font/fac_font.ttf");

    temp->credit_text = sfText_create();
    sfText_setPosition(temp->credit_text, get_vector(1775, 5));
    sfText_setFont(temp->credit_text, fac_font);
    temp->gear_text = sfText_create();
    sfText_setPosition(temp->gear_text, get_vector(1775, 45));
    sfText_setFont(temp->gear_text, fac_font);
    temp->cursor_info = sfText_create();
    sfText_setFont(temp->cursor_info, fac_font);
    sfText_setCharacterSize(temp->cursor_info, 8);
}

game_t *get_game_eng(void)
{
    game_t *temp = malloc(sizeof(game_t));

    setup_bar(temp);
    setup_values(temp);
    setup_background(temp);
    setup_game_texts(temp);
    temp->igs = NORMAL;
    temp->player = initialize_player();
    temp->turret_info = setup_info_bubble();
    temp->silo = get_sprite("assets/pics/reac.png");
    temp->player->player_sheet = get_sprite("assets/pics/hr_all.png");
    sfSprite_setOrigin(temp->player->player_sheet, get_vector(54, 68));
    sfSprite_setScale(temp->player->player_sheet, get_vector(0.5, 0.5));
    sfSprite_setPosition(temp->player->player_sheet, temp->player->coo);
    setup_money_ui(temp);
    setup_turret_bar(temp);

    return temp;
}
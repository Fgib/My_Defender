##
## EPITECH PROJECT, 2020
## my_runner
## File description:
## Makefile
##

SRC		=	main.c\
			player/player_back.c\
			player/player_front.c\
			editor/paint.c\
			editor/map_gum.c\
			editor/map_block.c\
			scenario/dir.c\
			scenario/load.c\
			scenario/details.c\
			scenario/wave_validator.c\
			scenario/turret_validator.c\
			scenario/scenario_validator.c\
			scenario/map_validator.c\
			scenario/utils.c\
			events_utils/mouse.c\
			events_utils/button.c\
			events_utils/clicks.c\
			events_utils/slider.c\
			events_utils/trigger.c\
			events_utils/scroling.c\
			events_utils/key_strokes.c\
			events_utils/start.c\
			about_map/map_loader.c\
			about_map/vmap_loader.c\
			about_map/map_printer.c\
			about_map/map_analizer.c\
			about_map/mini_map_printer.c\
			ennemies/finder.c\
			ennemies/printer.c\
			ennemies/spawner.c\
			ennemies/movements.c\
			ennemies/animation.c\
			ennemies/constructor.c\
			ennemies/wave_manager.c\
			ennemies/get_validator.c\
			ennemies/ennemies_events.c\
			textures/constructor.c\
			options/sound_level.c\
			options/keymap.c\
			utils/my_get.c\
			utils/lib_func.c\
			utils/math_trigo.c\
			utils/randomizer.c\
			utils/file_loading.c\
			utils/string_stuff.c\
			utils/math_vectors.c\
			free/game.c\
			events_loop/events_about.c\
			events_loop/events_dispatch.c\
			events_loop/events_game_eng.c\
			events_loop/events_selector.c\
			events_loop/events_end_menu.c\
			events_loop/events_game_eng2.c\
			events_loop/events_pause_menu.c\
			events_loop/events_start_menu.c\
			events_loop/events_editor_eng.c\
			events_loop/events_editor_menu.c\
			events_loop/events_settings_menu.c\
			turrets/levels.c\
			turrets/events.c\
			turrets/target.c\
			turrets/printer.c\
			turrets/movements.c\
			turrets/constructor1.c\
			turrets/constructor2.c\
			drawer/draw_about.c\
			drawer/draw_game1.c\
			drawer/draw_game2.c\
			drawer/draw_menu.c\
			drawer/draw_pause.c\
			drawer/drawer_utils.c\
			drawer/draw_selector.c\
			drawer/draw_end_menu.c\
			drawer/draw_settings1.c\
			drawer/draw_settings2.c\
			drawer/draw_settings3.c\
			drawer/drawer_dispatch.c\
			drawer/draw_editor_eng.c\
			load_structs/load_menu.c\
			load_structs/load_keys.c\
			drawer/draw_editor_menu.c\
			load_structs/load_about.c\
			load_structs/load_game1.c\
			load_structs/load_game2.c\
			load_structs/load_pause.c\
			load_structs/load_sounds.c\
			load_structs/load_settings1.c\
			load_structs/load_settings2.c\
			load_structs/load_selector.c\
			load_structs/load_dispatch.c\
			load_structs/load_end_menu.c\
			load_structs/load_editor_eng1.c\
			load_structs/load_editor_eng2.c\
			load_structs/load_editor_menu.c\
			load_structs/load_turrets_info.c\
			initialisation/init_button.c\
			initialisation/init_player.c\
			initialisation/init_window.c\
			initialisation/init_slider.c\
			initialisation/init_trigger.c\


OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-I../include -lm -g3 $(EFLAGS) 
# -fsanitize=address

DEBUG		=	@

NAME		=	my_defender

EFLAGS		=	-Werror -Wall  -Wextra -Wpedantic

CSFMLFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

DEBUG_FLAG	=	--no-print-directory

all: do

do:	$(OBJ)
	$(DEBUG) gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS) $(CFLAGS) -g3
	$(DEBUG) make $(DEBUG_FLAG) clean
	$(DEBUG) mv $(NAME) ../

clean:
	$(DEBUG) rm -rf $(OBJ)
	$(DEBUG) rm -rf *.vgcore*
	$(DEBUG) rm -rf ../$(NAME)

fclean:	clean
	$(DEBUG) rm -rf $(NAME)

re:	fclean all

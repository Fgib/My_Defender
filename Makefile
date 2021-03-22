##
## EPITECH PROJECT, 2020
## my_hunter
## File description:
## Makefile
##

SRC		=	src

ROOT	=	.

DEBUG	=	@
COMPIL	=	make

#FLAGS
FLAGS_COMPIL	=	-C
FLAGS_CLEAN		=	clean
FLAGS_FCLEAN	=	fclean
FLAGS_DEBUG		=	--no-print-directory

#COLORS
WHITE	=	\e[0m
RED		=	\e[1;31m
GREEN	=	\e[1;32m
YELLOW	=	\e[1;33m
BLUE	=	\e[1;34m

all:
	$(DEBUG) printf "$(YELLOW)========== COMPILATION ==========\n$(WHITE)"
	$(DEBUG) printf "$(RED)  Projet CPE_My_Defender_2021$(YELLOW)  \n\n$(WHITE)"
	$(DEBUG) $(COMPIL) $(FLAGS_DEBUG) $(FLAGS_COMPIL) $(ROOT)/$(SRC)
	$(DEBUG) printf "$(GREEN)\nCompilation Success\n$(WHITE)"
	$(DEBUG) printf "$(YELLOW)Enjoy the game\n\n$(WHITE)"

clean:
	$(DEBUG) printf "$(RED)Binary deletion\n$(WHITE)"
	$(DEBUG) $(COMPIL) $(FLAGS_DEBUG) $(FLAGS_CLEAN) $(FLAGS_COMPIL) $(ROOT)/$(SRC)

fclean: clean
	$(DEBUG) printf "$(RED)All non-build files deletion :\n$(WHITE)"
	$(DEBUG) $(COMPIL) $(FLAGS_DEBUG) $(FLAGS_FCLEAN) $(FLAGS_COMPIL) $(ROOT)/$(SRC)
	$(DEBUG) printf "$(RED)    -removed object files\n$(WHITE)"
	$(DEBUG) printf "$(RED)    -removed valgrind files\n$(WHITE)"
	$(DEBUG) printf "$(RED)    -removed emacs temporary files\n$(WHITE)"
	
re:	
	$(DEBUG) printf "$(YELLOW)============CLEANING============\n$(WHITE)"
	$(DEBUG) make $(FLAGS_DEBUG) fclean
	$(DEBUG) printf "$(GREEN)Successfully cleaned\n\n$(WHITE)"
	$(DEBUG) make $(FLAGS_DEBUG) all

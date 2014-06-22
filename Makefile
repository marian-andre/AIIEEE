# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgranet <jgranet@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 16:48:39 by jgranet           #+#    #+#              #
#    Updated: 2014/06/22 14:54:45 by mlemort          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SER = serveur
NAME_GFX = gfx_bin
INC_DIR = ./includes
SRC_DIR_SER = ./srcs/serveur
OBJ_DIR_SER = ./objs/serveur
SRC_DIR_GFX = ./srcs/gfx
OBJ_DIR_GFX = ./objs/gfx
BIN_DIR = ./bin/

LIBFT = libft
LIB_NAME = libft/libft.a
SDL2 = SDL2-2.0.3/build/.libs/libSDL2.a
PHP = php-5.5.13/sapi/cli/php
UNITS_SER = $(shell ls $(SRC_DIR_SER) | grep .c)
UNITS_O_SER = $(UNITS_SER:.c=.o)
UNITS_GFX = $(shell ls $(SRC_DIR_GFX) | grep .c)
UNITS_O_GFX = $(UNITS_GFX:.c=.o)
UNITS_H = $(shell ls $(INC_DIR) | grep .h)

SRCS_SER = $(patsubst %,$(SRC_DIR_SER)/%,$(UNITS_SER))
OBJS_SER = $(patsubst %,$(OBJ_DIR_SER)/%,$(UNITS_O_SER))
SRCS_GFX = $(patsubst %,$(SRC_DIR_GFX)/%,$(UNITS_GFX))
OBJS_GFX = $(patsubst %,$(OBJ_DIR_GFX)/%,$(UNITS_O_GFX))

LIBFLAGS = -L$(LIBFT) -lft
FLAGS = -Wall -Werror -Wextra -O1 -I libft/includes -I SDL2-2.0.3/include

CC = gcc $(FLAGS)

RM = /bin/rm -f

all: $(SDL2) $(PHP) $(LIB_NAME) $(BIN_DIR)$(NAME_SER) $(BIN_DIR)$(NAME_GFX)

$(PHP):
	cd php-5.5.13 && ./configure CC=clang --enable-sockets --enable-pcntl \
		--with-config-file-path=./ && make

$(SDL2):
	cd SDL2-2.0.3 && ./configure CC=clang && make

$(LIB_NAME):
	@make -C $(LIBFT)

$(BIN_DIR)$(NAME_SER): $(OBJS_SER) $(LIB_NAME)
	@echo "Objects [$(NAME_SER)]:\033[1;33m DONE !\033[m"
	@$(CC) -o $@ $^ $(LIBFLAGS)
	@echo "Program [$(NAME_SER)] :\033[1;33m DONE !\033[m"

$(OBJ_DIR_SER)/%.o: $(SRC_DIR_SER)/%.c ./includes/serveur.h
	@$(CC) -c -o $@ $< -I$(INC_DIR)

$(BIN_DIR)$(NAME_GFX): $(OBJS_GFX) $(LIB_NAME)
	@echo "Objects [$(NAME_GFX)]:\033[1;33m DONE !\033[m"
	@$(CC) -o $@ $^ $(LIBFLAGS) -L SDL2-2.0.3/build/.libs -l SDL2
	@echo "Program [$(NAME_GFX)] :\033[1;33m DONE !\033[m"

$(OBJ_DIR_GFX)/%.o: $(SRC_DIR_GFX)/%.c ./includes/graphic.h
	@$(CC) -c -o $@ $< -I$(INC_DIR)

clean:
	@make -C libft clean
	@$(RM) $(OBJS_SER)
	@$(RM) $(OBJS_GFX)
	@echo "Make clean :\033[1;33m DONE !\033[m"

fclean : clean
	@make -C libft fclean
	@$(RM) $(BIN_DIR)$(NAME_SER)
	@$(RM) $(BIN_DIR)$(NAME_GFX)
	@echo "Make fclean :\033[1;33m DONE !\033[m"

phpfc :
	@make -C php-5.5.13 clean

sdlfc :
	@make -C SDL2-2.0.3 clean

re: fclean all

.PHONY: all clean fclean re

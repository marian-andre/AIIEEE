# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgranet <jgranet@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 16:48:39 by jgranet           #+#    #+#              #
#    Updated: 2014/06/08 16:28:46 by mlemort          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SER = serveur
INC_DIR = ./includes
SRC_DIR_SER = ./srcs/serveur
OBJ_DIR_SER = ./objs/serveur
BIN_DIR = ./bin/

LIBFT = libft
LIB_NAME = libft/libft.a
SDL2 = SDL2-2.0.3/build/.libs/libSDL2.a
UNITS_SER = $(shell ls $(SRC_DIR_SER) | grep .c)
UNITS_O_SER = $(UNITS_SER:.c=.o)
UNITS_H = $(shell ls $(INC_DIR) | grep .h)

SRCS_SER = $(patsubst %,$(SRC_DIR_SER)/%,$(UNITS_SER))
OBJS_SER = $(patsubst %,$(OBJ_DIR_SER)/%,$(UNITS_O_SER))
HEADS = $(patsubst %,$(INC_DIR)/%,$(UNITS_H))

LIBFLAGS = -L$(LIBFT) -lft -L SDL2-2.0.3/build/.libs -l SDL2
FLAGS = -Wall -Werror -Wextra -I libft/includes -I SDL2-2.0.3/include

CC = gcc $(FLAGS)

RM = /bin/rm -f

all: $(SDL2) $(LIB_NAME) $(BIN_DIR)$(NAME_SER) testsdl2

$(SDL2):
	cd SDL2-2.0.3 && \
	./configure CC=clang && \
	make

$(LIB_NAME):
	@make -C $(LIBFT) re

$(BIN_DIR)$(NAME_SER): $(OBJS_SER)
	@echo "Objects [$(NAME_SER)]:\033[1;33m DONE !\033[m"
	@$(CC) -o $@ $^ $(LIBFLAGS)
	@echo "Program [$(NAME_SER)] :\033[1;33m DONE !\033[m"

$(OBJ_DIR_SER)/%.o: $(SRC_DIR_SER)/%.c $(HEADS)
	@$(CC) -c -o $@ $< -I$(INC_DIR)

testsdl2: testsdl2.c
	$(CC) $(LIBFLAGS) testsdl2.c -o testsdl2

clean:
	@make -C libft clean
	@make -C SDL2-2.0.3 clean
	@$(RM) $(OBJS_SER)
	@echo "Make clean :\033[1;33m DONE !\033[m"

fclean : clean
	@make -C libft fclean
	@rm -f lib/libSDL2.a
	@$(RM) $(BIN_DIR)$(NAME_SER)
	@echo "Make fclean :\033[1;33m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re

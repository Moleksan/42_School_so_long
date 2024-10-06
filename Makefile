# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 19:35:42 by moleksan          #+#    #+#              #
#    Updated: 2024/07/04 13:18:44 by moleksan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long 
CC      = gcc 
FLAGS   = -Wall -Wextra -Werror -Imlx
RM      = rm -rf
YELLOW  = \033[0;33m
RED     = \033[0;31m

HED_SRC = solong.h 
HED_DIR = slnglib/
HEADER  = $(addprefix $(HED_DIR), $(HED_SRC))

PRJ_SRC = map.c render.c main.c keyhook.c ft_printf.c move.c map_check.c \
          map_h.c move_set.c bonus.c
PRJ_DIR = game/
PRJ_PTH = $(addprefix $(PRJ_DIR), $(PRJ_SRC))
OBJ_P   = $(PRJ_PTH:.c=.o)

GNL_SRC = get_next_line.c get_next_line_utils.c
GNL_DIR = gnl/
FUNC    = $(addprefix $(GNL_DIR), $(GNL_SRC))
OBJ_F   = $(FUNC:.c=.o)

%.o: %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_F) $(OBJ_P)
	$(CC) $(OBJ_F) $(OBJ_P) -Lmlx -lmlx -lX11 -lXext -lGL -lm -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_P)
	$(RM) $(OBJ_F)
	@echo "$(YELLOW)Object files deleted!$(DEFAULT)" 

fclean: 
	$(RM) $(OBJ_P)
	$(RM) $(OBJ_F)
	$(RM) $(NAME)
	@echo "$(RED)All deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re


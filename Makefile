# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:20:57 by tbeaudoi          #+#    #+#              #
#    Updated: 2022/11/03 20:22:51 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

# SRCS_PATH = src/

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

PRINTF = include/printf/libftprintf.a
PRINTF_PATH = include/printf/

GNL_SRC = include/get_next_line/get_next_line.c \
			include/get_next_line/get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:.c=.o)

SRCS = src/so_long.c \
			src/initialize.c \
			src/errors.c \
			src/map_parsing1.c \
			src/map_parsing2.c \
			src/init_imgs.c \
			src/player_moves.c \
			src/flood_my_shorts.c \
			src/mlx_file.c \
			 
OBJS = $(SRCS:.c=.o)

all: 	$(NAME)


$(NAME): $(OBJS) $(GNL_OBJ)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(PRINTF_PATH)
	$(CC) $(CFLAGS)  -o $@ $^ $(LIBFT) $(PRINTF) -L. -lmlx -framework OpenGL -framework AppKit 
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@$(RM) $(OBJS) $(GNL_OBJ)
	@make -C $(LIBFT_PATH)  clean
	@make -C $(PRINTF_PATH)  clean

fclean:	clean
	@$(RM) $(NAME) $(LIBFT) 

re:		fclean all
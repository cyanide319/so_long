# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:20:57 by tbeaudoi          #+#    #+#              #
#    Updated: 2022/10/10 15:47:48 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

SRCS_PATH = src/

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

PRINTF = include/printf/libftprintf.a
PRINTF_PATH = include/printf/

GNLSRC = include/get_next_line/get_next_line.c \
			include/get_next_line/get_next_line_utils.c
GNLOBJ = $(GNLSRC:.c=.o)

SRCS_FILES = so_long.c \
			 
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)

all: 	$(NAME)


$(NAME): $(OBJS) $(GNLOBJ)
	-@$(MAKE) -C $(LIBFT_PATH)
	-@$(MAKE) -C $(PRINTF_PATH)
	-@$(CC) $(CFLAGS)  -o $@ $^ $(LIBFT) -L. -lmlx -framework OpenGL -framework AppKit 
	-@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH)  clean
	@make -C $(PRINTF_PATH)  clean

fclean:	clean
	@$(RM) $(NAME) $(LIBFT) 

re:		fclean all
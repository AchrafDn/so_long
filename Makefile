# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adadoun <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 23:53:05 by adadoun           #+#    #+#              #
#    Updated: 2023/03/21 23:53:06 by adadoun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
#LIBFT = libft/libft.a
CFILES = Mandatory/so_long.c \
		Mandatory/parsing.c \
		Mandatory/parssing_1utils.c \
		Mandatory/create_map.c \
		Mandatory/key_moves.c \
		Mandatory/key_moves2.c \
		Mandatory/ft_split.c \
		Mandatory/ft_strdup.c \
		Mandatory/ft_strcmp.c \
		Mandatory/itoa.c \
		ft_printf.c \
		ft_printf_utils.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

BFILES = Bonus/so_long.c \
		Bonus/parsing.c \
		Bonus/parssing_1utils.c \
		Bonus/create_map.c \
		Bonus/key_moves.c \
		Bonus/key_moves2.c \
		Bonus/ft_split.c \
		Bonus/ft_strdup.c \
		Bonus/ft_strcmp.c \
		Bonus/itoa.c \
		ft_printf.c \
		ft_printf_utils.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

OBJ = ${CFILES:.c=.o}
B_OBJ = ${BFILES:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -lmlx -framework OpenGL -framework appkit $(OBJ) -o $(NAME)

bonus: $(B_OBJ)
	$(CC) -lmlx -framework OpenGL -framework appkit $(B_OBJ) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all


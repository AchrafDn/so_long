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
CFILES = so_long.c \
		parsing.c \
		parssing_1utils.c \
		moves.c \
		ft_split.c \
		ft_strdup.c \
		ft_strcmp.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

OBJ = ${CFILES:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -lmlx -framework OpenGL -framework appkit $(OBJ) -o ${NAME}

.c.o:
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all


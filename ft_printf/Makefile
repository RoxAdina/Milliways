# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romoldov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 16:41:14 by romoldov          #+#    #+#              #
#    Updated: 2018/03/09 19:25:29 by romoldov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Werror -Wall -Wextra
SRC		= *.c
OBJ		= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft
		cp libft/libft.a ./$(NAME)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ): $(SRC)
		gcc $(FLAGS) -I. -c $(SRC)
clean:
		rm -f $(OBJ)
		make -C libft/ clean
fclean: clean
		make -C libft/ fclean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

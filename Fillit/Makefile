# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romoldov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 17:53:15 by romoldov          #+#    #+#              #
#    Updated: 2018/02/27 17:47:38 by romoldov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC=	ft_unittest.c\
		ft_filetostr.c\
		ft_errormsg.c\
		ft_checkgrid.c\
		ft_minsquare.c\
		ft_checktetro.c\
		ft_checkfile.c\
		ft_makegrid.c\
		ft_algotetro.c\
		ft_tetrotoarray.c\
		ft_tetrotogrid.c\
		ft_tetroinit.c\

OBJ= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC= gcc
CFLAGS= -Wall -Wextra -Werror

LIBFT= ./libft/libft.a
LIBINC= -I./libft
LIBLINK= -L./libft -lft

SRCDIR= ./src/
INCDIR= ./src/
OBJDIR= ./obj/

all: $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): obj libft $(OBJ) 
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

remlib:
	rm -rf $(LIBFT)

remoblib:
	make fclean -C ./libft/

clean: remoblib
	rm -rf $(OBJDIR)

fclean: clean remlib
	rm -rf $(NAME)

re: fclean all

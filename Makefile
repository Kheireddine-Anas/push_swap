# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akheired <akheired@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 10:34:56 by akheired          #+#    #+#              #
#    Updated: 2024/05/19 13:39:11 by akheired         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRC =	push_swap.c utils1.c utils2.c utils3.c utils4.c utils.c ft_split.c actions.c actions1.c actions2.c
BSRC =	checker.c utils1.c utils2.c utils3.c utils4.c utils.c ft_split.c actions.c actions1.c actions2.c

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${BSRC:.c=.o}

all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
				$(CC) $(CFLAGS) $^ -o $(NAME_BONUS)

clean : 
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all
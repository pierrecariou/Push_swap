# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 11:21:35 by pcariou           #+#    #+#              #
#    Updated: 2021/12/20 18:15:34 by pcariou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

HEADER		= ./

SRCS		=	srcs/main.c \
				srcs/operations.c \
				srcs/operations1.c \
				srcs/algorithm.c \
				srcs/algorithm1.c \
				srcs/algorithm2.c \
				srcs/algorithm3.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

.c.o:
	clang $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADER)

$(NAME):	$(OBJS)
	cd libft && make
	clang -o $(NAME) $(OBJS) libft/libft.a

clean:
	rm -f $(OBJS) && cd libft && make clean

fclean:		clean
	rm -f $(NAME) && cd libft && make fclean

re:			fclean all

.PHONY:		all clean fclean re

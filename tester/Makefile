# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 11:21:35 by pcariou           #+#    #+#              #
#    Updated: 2022/01/03 15:06:43 by pcariou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker

HEADER		= ./

SRCS		=	checker.c \
				operations.c \
				operations1.c \
				execute.c

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 13:44:44 by gde-win           #+#    #+#              #
#    Updated: 2024/01/05 01:14:18 by gde-win          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			server \
				client

CC :=			cc

CFLAGS :=		-Wall -Wextra -Werror -I. -fsanitize=address -g

FUNCTIONS :=	server.c \
				client.c

SRCS :=			$(FUNCTIONS)

OBJS :=			$(SRCS:.c=.o)

INCLUDE :=		server.h \
				client.h

LIBFT :=		libft

all:			$(LIBFT) $(NAME)

$(LIBFT):
					@make -C $@

$(NAME):		$(OBJS)
					$(CC) $(CFLAGS) -Wl,libft/libft.a $@.o -o $@

clean:
					rm -rf $(OBJS)
					@make clean -C $(LIBFT)

fclean:			clean
					rm -rf $(NAME)
					rm -rf libft/libft.a

re:				fclean all

.PHONY:			all clean fclean re libft

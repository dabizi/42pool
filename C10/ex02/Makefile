# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 11:04:22 by jgrandne          #+#    #+#              #
#    Updated: 2019/07/24 14:39:32 by jgrandne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_tail
SRC=ft_tail.c ft_error.c ft_annexe.c
OBJECTS=$(SRC:.c=.o)
HEADERS=includes
CFLAGS= -Wall -Wextra -Werror
CC = gcc

${NAME}:	${OBJECTS}
			${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}

all: ${NAME}

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

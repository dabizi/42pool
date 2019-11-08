# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 10:57:12 by jgrandne          #+#    #+#              #
#    Updated: 2019/07/24 14:37:58 by jgrandne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_cat
SRC=ft_cat.c tools.c
OBJECTS=$(SRC:.c=.o)
HEADERS=includes
CFLAGS= -Wall -Wextra -Werror

${NAME}:	${OBJECTS}
			${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}

all: ${NAME}

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

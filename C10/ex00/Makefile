# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 10:26:38 by jgrandne          #+#    #+#              #
#    Updated: 2019/07/24 10:58:24 by jgrandne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_display_file
SRC=ft_display_file.c
OBJECTS=$(SRC:.c=.o)
HEADERS=includes
CFLAGS= -Wall -Wextra -Werror

.c.o:
	gcc ${CFLAGS} -I${HEADERS} -c $< -o $(<:.c=.o)

all: ${NAME}

make_display: $(OBJECTS)
	gcc -Wall -Wextra -Werror $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

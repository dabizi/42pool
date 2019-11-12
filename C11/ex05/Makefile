# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 11:49:51 by jgrandne          #+#    #+#              #
#    Updated: 2019/07/22 12:39:23 by jgrandne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=do-op
SRCS=do_op.c ft_tools.c ft_operator.c
OBJECTS=$(SRCS:.c=.o)
HEADERS_FOLDER=includes
CFLAGS = -Wall -Wextra -Werror

.c.o:
		gcc ${CFLAGS} -I$(HEADERS_FOLDER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o ${NAME}

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

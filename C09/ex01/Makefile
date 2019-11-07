# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 19:16:24 by jgrandne          #+#    #+#              #
#    Updated: 2019/07/18 22:57:25 by jgrandne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS=$(SRCS:.c=.o)
HEADERS_FOLDER=includes

.c.o:
	gcc -Wall -Wextra -Werror -I$(HEADERS_FOLDER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/03 00:30:28 by pholster       #+#    #+#                 #
#    Updated: 2019/10/03 00:30:28 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ../src/get_headers
SRC = get_headers sort_headers
SRC := $(SRC:%=%.c)

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) $(SRC)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE)

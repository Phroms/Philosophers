# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 21:07:33 by agrimald          #+#    #+#              #
#    Updated: 2024/02/29 19:42:05 by agrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
CFLAGS = -Wall -Werror -Wextra #-g #-fsanitize=address

SRC = arguments.c init_program.c rutinas.c utils.c
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) Makefile
					@mkdir -p $(@D)
					@gcc $(CFLAGS) -o $@ $(OBJECTS)
					@printf "\nCompiled successfully!!\n"

fclean: clean
		@rm -rf $(NAME)

clean:
		@rm -rf $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re

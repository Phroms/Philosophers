# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 21:07:33 by agrimald          #+#    #+#              #
#    Updated: 2024/03/07 18:53:40 by agrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
CFLAGS = -Wall -Werror -Wextra -pthread -fsanitize=thread

SRC = arguments.c init_program.c rutinas.c utils.c exit.c
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

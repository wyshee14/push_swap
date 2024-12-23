# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:31:35 by wshee             #+#    #+#              #
#    Updated: 2024/12/23 21:46:02 by wshee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program Name
NAME = push_swap

#The -I (uppercase i) flag is used to add a directory to the list of directories
#the compiler searches for header files (#include directives).
#Directories
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = include/
SRC_DIR = src/
INC = -I$(INC_DIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INC)

#Source Directories
OPERATION_DIR = $(SRC_DIR)operation/

OPERATION_SRC_FILES = push.c	reverse_rotate.c	rotate.c	swap.c

#addprefix <prefix>, <list>
#<prefix> is the string that added to the beginning of each word
SRC = $(wildcard $(SRC_DIR)*.c) \
		$(addprefix $(OPERATION_DIR)/, $(OPERATION_SRC_FILES))

OBJ_SRC = $(SRC:.c=.o)

all: $(NAME)
	@make -C libft

$(NAME) : $(OBJ_SRC)
	ar rcs $(NAME) $(OBJ_SRC)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_SRC)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

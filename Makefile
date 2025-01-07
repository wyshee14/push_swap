# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:31:35 by wshee             #+#    #+#              #
#    Updated: 2025/01/07 19:11:55 by wshee            ###   ########.fr        #
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

CC = cc -g3 -O0
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)

#Source Directories
OPERATION_DIR = $(SRC_DIR)operation/

OPERATION_SRC_FILES = push.c	reverse_rotate.c	rotate.c	swap.c

#addprefix <prefix>, <list>
#<prefix> is the string that added to the beginning of each word
SRC = $(wildcard $(SRC_DIR)*.c) \
		$(addprefix $(OPERATION_DIR)/, $(OPERATION_SRC_FILES))

OBJ_SRC = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_SRC)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ_SRC) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_SRC)
	@make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus

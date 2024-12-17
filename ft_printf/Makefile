# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 14:34:26 by wshee             #+#    #+#              #
#    Updated: 2024/12/03 16:15:27 by wshee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

#The -I (uppercase i) flag is used to add a directory to the list of directories
#the compiler searches for header files (#include directives).
INC_DIR = include/
INC = -I$(INC_DIR)

CFLAGS = -Wall -Wextra -Werror $(INC)

SRC_DIR = src/
#addprefix <prefix>, <list>
#<prefix> is the string that added to the beginning of each word
SRC = $(addprefix $(SRC_DIR), \
		ft_printf.c		ft_printchar.c	ft_printstr.c	ft_printaddress.c	\
		ft_printnbr.c	ft_printhexa.c	ft_print_unsigned_nbr.c)

OBJ_SRC = $(SRC:.c=.o)

all: $(NAME)

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

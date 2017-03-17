# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/12 15:20:39 by mcastres          #+#    #+#              #
#    Updated: 2016/12/19 17:38:52 by mcastres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME = ft_printf

#Lib
LIB = srcs/libftprintf.a

#Flag
FLAGS = -Wall -Wextra -Werror

#Srcs_PATH
SRCS_PATH = ./srcs

#SRCS_NAME
SRCS_NAME = ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_strlen.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_putnbr.c\
		ft_atoi.c\
		ft_strsub.c\
		ft_itoa.c\
		ft_strdup.c\
		ft_isoption.c\
		ft_unsignedintlen.c\
		ft_intlen.c\
		ft_print_value.c\
		ft_print_option.c\
		ft_putnbru.c\

# COLORS
C_NO =	"\033[00m"
C_OK =	"\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

# DBG MESSAGE
SUCCESS	= $(C_GOOD)SUCCESS$(C_NO)
OK = $(C_OK)OK$(C_NO)

#SRCS
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

#Objects
OBJ = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I includes -c $(SRCS)
	@ar rc $(LIB) $(OBJ)
	@ranlib $(LIB)

%.o: %.c
	@gcc -I includes -o $@ -c $< $(FLAGS)

clean:
	@rm -rf $(OBJ) $(OBJ_MAIN)

fclean: clean
	@rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re

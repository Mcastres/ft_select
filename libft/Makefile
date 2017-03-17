# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 11:10:38 by mcastres          #+#    #+#              #
#    Updated: 2017/03/17 15:18:07 by mcastres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_freetabb.c ft_tabbpushback.c ft_tabblen.c ft_tabbcreate.c ft_getcwd.c ft_removelastslash.c ft_removendslash.c ft_triplejoin.c ft_freetab.c ft_open.c ft_opendir.c ft_isenv.c ft_escapequote.c ft_tabtospace.c ft_tabdup.c ft_tabtrim.c ft_putabenv.c ft_tabcreate.c ft_tabdelone.c ft_isupper.c ft_islower.c ft_tabpushback.c ft_tablen.c ft_thereisnothing.c ft_lstfree.c ft_del.c ft_lstpushfront.c ft_lstpushback.c ft_putab.c ft_print_list.c ft_hashtab.c ft_rot42.c ft_lstnew.c ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstmap.c ft_lstiter.c ft_itoa.c ft_words.c ft_strsplit.c ft_strtrim_c.c ft_strnstr.c ft_putnbr_fd.c ft_putnbr.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl.c ft_putstr.c ft_putchar.c ft_strtrim.c ft_strjoin.c ft_strsub.c ft_strnequ.c ft_strequ.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c ft_memalloc.c ft_strstr.c ft_strlcat.c ft_memcmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_tolower.c ft_toupper.c
OBJ = ft_freetabb.o ft_tabbpushback.o ft_tabblen.o ft_tabbcreate.o ft_getcwd.o ft_removelastslash.o ft_removendslash.o ft_triplejoin.o ft_freetab.o ft_open.o ft_opendir.o ft_isenv.o ft_escapequote.o ft_tabtospace.o ft_tabdup.o ft_tabtrim.o ft_putabenv.o ft_tabcreate.o ft_tabdelone.o ft_isupper.o ft_islower.o ft_tabpushback.o ft_tablen.o ft_thereisnothing.o ft_lstfree.o ft_del.o ft_lstpushfront.o ft_lstpushback.o ft_putab.o ft_print_list.o ft_hashtab.o ft_rot42.o ft_lstnew.o ft_lstadd.o ft_lstmap.o ft_lstdelone.o ft_lstdel.o ft_lstiter.o ft_itoa.o ft_words.o ft_strsplit.o ft_strtrim_c.o ft_strnstr.o ft_putnbr_fd.o ft_putnbr.o ft_putendl_fd.o ft_putstr_fd.o ft_putchar_fd.o ft_putendl.o ft_putstr.o ft_putchar.o ft_strtrim.o ft_strjoin.o ft_strsub.o ft_strnequ.o ft_strequ.o ft_strclr.o ft_strdel.o ft_strnew.o ft_memdel.o ft_memalloc.o ft_strstr.o ft_strlcat.o ft_memcmp.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcmp.o ft_strncmp.o ft_strcat.o ft_strncat.o ft_strchr.o ft_strrchr.o ft_atoi.o ft_isalnum.o ft_isalpha.o ft_isdigit.o ft_isascii.o ft_isprint.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_tolower.o ft_toupper.o

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.PHONY: clean
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

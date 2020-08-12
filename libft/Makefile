# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 12:08:49 by rgalyeon          #+#    #+#              #
#    Updated: 2020/07/25 15:13:12 by rgalyeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra
CC = gcc
NORM = norminette
INCLUDES = ./includes/
OFILES = *.o

CHAR_FILES = ./srcs/char/ft_isalnum.c \
			 ./srcs/char/ft_isalpha.c \
			 ./srcs/char/ft_isascii.c \
			 ./srcs/char/ft_isdigit.c \
			 ./srcs/char/ft_isprint.c \
			 ./srcs/char/ft_isspace.c \
			 ./srcs/char/ft_tolower.c \
			 ./srcs/char/ft_toupper.c

CONV_FILES = ./srcs/conv/ft_atoi.c \
			 ./srcs/conv/ft_ftoa.c \
			 ./srcs/conv/ft_itoa.c 

MATH_FILES = ./srcs/math/ft_int_len.c \
			 ./srcs/math/ft_pow.c \
			 ./srcs/math/ft_isprime.c \
			 ./srcs/math/ft_next_prime.c 

MEM_FILES = ./srcs/memory/ft_bzero.c \
			./srcs/memory/ft_memalloc.c \
			./srcs/memory/ft_memccpy.c \
			./srcs/memory/ft_memchr.c \
			./srcs/memory/ft_memcmp.c \
			./srcs/memory/ft_memcpy.c \
			./srcs/memory/ft_memdel.c \
			./srcs/memory/ft_memmove.c \
			./srcs/memory/ft_memset.c \
			./srcs/memory/ft_gc_helper.c \
			./srcs/memory/ft_mem_free_all.c \
			./srcs/memory/ft_mem_free.c

PUT_FILES = ./srcs/put/ft_putchar.c \
			./srcs/put/ft_putchar_fd.c \
			./srcs/put/ft_putendl.c \
			./srcs/put/ft_putendl_fd.c \
			./srcs/put/ft_putnbr.c \
			./srcs/put/ft_putnbr_fd.c \
			./srcs/put/ft_putstr.c \
			./srcs/put/ft_putstr_fd.c \
			./srcs/put/ft_putchar_fd_uni.c

STR_FILES = ./srcs/string/ft_strcat.c \
			./srcs/string/ft_strchr.c \
			./srcs/string/ft_strclr.c \
			./srcs/string/ft_strcmp.c \
			./srcs/string/ft_strcpy.c \
			./srcs/string/ft_strdel.c \
			./srcs/string/ft_strdup.c \
			./srcs/string/ft_strequ.c \
			./srcs/string/ft_striter.c \
			./srcs/string/ft_striteri.c \
			./srcs/string/ft_strjoin.c \
			./srcs/string/ft_strlcat.c \
			./srcs/string/ft_strlen.c \
			./srcs/string/ft_strmap.c \
			./srcs/string/ft_strmapi.c \
			./srcs/string/ft_strncat.c \
			./srcs/string/ft_strncmp.c \
			./srcs/string/ft_strncpy.c \
			./srcs/string/ft_strnequ.c \
			./srcs/string/ft_strnew.c \
			./srcs/string/ft_strnstr.c \
			./srcs/string/ft_strrchr.c \
			./srcs/string/ft_strreverse.c \
			./srcs/string/ft_strsplit.c \
			./srcs/string/ft_strstr.c \
			./srcs/string/ft_strsub.c \
			./srcs/string/ft_strtrim.c \
			./srcs/string/ft_splitwsp.c \
			./srcs/string/ft_strnjoin.c \
			./srcs/string/ft_free_strarr.c \
			./srcs/string/ft_putnstr.c \
			./srcs/string/ft_str_upper.c \
 			./srcs/string/get_next_line.c \
 			./srcs/string/ft_vstrpb.c \
 			./srcs/string/ft_vstrdel.c \
 			./srcs/string/ft_vstrpopfront.c \
 			./srcs/string/ft_vstrfind.c \
 			./srcs/string/ft_makestr.c

LIST_FILES = ./srcs/struct/list/ft_lstadd.c \
			 ./srcs/struct/list/ft_lstdel.c \
			 ./srcs/struct/list/ft_lstdelone.c \
			 ./srcs/struct/list/ft_lstiter.c \
			 ./srcs/struct/list/ft_lstmap.c \
			 ./srcs/struct/list/ft_lstnew.c \
			 ./srcs/struct/list/ft_lst_map_init.c

MATRIX_FILES = ./srcs/struct/matrix/ft_matrix_copy.c \
			   ./srcs/struct/matrix/ft_matrix_create.c \
			   ./srcs/struct/matrix/ft_matrix_digit_mul.c \
			   ./srcs/struct/matrix/ft_matrix_max.c \
			   ./srcs/struct/matrix/ft_matrix_mul.c \
			   ./srcs/struct/matrix/ft_matrix_print.c \
			   ./srcs/struct/matrix/ft_matrix_sub.c \
			   ./srcs/struct/matrix/ft_matrix_trans.c

RB_TREES_FILES = ./srcs/struct/rb_trees/ft_rb_del_fix.c \
				 ./srcs/struct/rb_trees/ft_rb_del_node.c \
				 ./srcs/struct/rb_trees/ft_rb_find_node.c \
				 ./srcs/struct/rb_trees/ft_rb_free.c \
				 ./srcs/struct/rb_trees/ft_rb_infix.c \
				 ./srcs/struct/rb_trees/ft_rb_ins_fix.c \
				 ./srcs/struct/rb_trees/ft_rb_ins_node.c \
				 ./srcs/struct/rb_trees/ft_rb_left_rot.c \
				 ./srcs/struct/rb_trees/ft_rb_node_creat.c \
				 ./srcs/struct/rb_trees/ft_rb_prefix.c \
				 ./srcs/struct/rb_trees/ft_rb_print_key.c \
				 ./srcs/struct/rb_trees/ft_rb_right_rot.c \
				 ./srcs/struct/rb_trees/ft_rb_suffix.c \
				 ./srcs/struct/rb_trees/ft_rb_tree_init.c \
				 ./srcs/struct/rb_trees/ft_rb_free_map.c 

VEC_FILES = ./srcs/struct/vector/ft_vec_init.c \
			./srcs/struct/vector/ft_vec_push.c \
			./srcs/struct/vector/ft_ptr_vec_init.c \
			./srcs/struct/vector/ft_ptr_vec_push.c \
			./srcs/struct/vector/vec_pro_init.c \
			./srcs/struct/vector/vec_pro_push.c \
			./srcs/struct/vector/ft_vec_string_push.c \
			./srcs/struct/vector/ft_int_vec_push.c \
			./srcs/struct/vector/ft_int_vec_init.c


HASHTABLE_FILES = ./srcs/struct/hashtable/ft_ht_create.c \
                  ./srcs/struct/hashtable/ft_ht_del.c \
                  ./srcs/struct/hashtable/ft_ht_del_item.c \
                  ./srcs/struct/hashtable/ft_ht_delete.c \
                  ./srcs/struct/hashtable/ft_ht_get_hash.c \
                  ./srcs/struct/hashtable/ft_ht_hash.c \
                  ./srcs/struct/hashtable/ft_ht_insert.c \
                  ./srcs/struct/hashtable/ft_ht_new_item.c \
                  ./srcs/struct/hashtable/ft_ht_print.c \
                  ./srcs/struct/hashtable/ft_ht_resize.c \
                  ./srcs/struct/hashtable/ft_ht_search.c \
                  ./srcs/struct/hashtable/ft_ht_print.c

SORT_FILES = ./srcs/sort/ft_swap.c \
             ./srcs/sort/ft_swaps.c \
             ./srcs/sort/quick_sort_by_name.c \
             ./srcs/sort/ft_insertion_sort.c

DEVELOPMENT_UTILS = ./srcs/develop_utils/do_nothing.c \

FILES = $(CHAR_FILES) $(CONV_FILES) $(MATH_FILES) $(MEM_FILES) $(PUT_FILES) \
		$(STR_FILES) $(LIST_FILES) $(MATRIX_FILES) $(RB_TREES_FILES) \
		$(VEC_FILES) $(SORT_FILES) $(HASHTABLE_FILES)
OBJECTS = $(FILES:.c=.o)
DEPS = $(FILES:.c=.d)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\033[33mLibrary compiled!\033[0m"

%.o: %.c
	@echo "\033[34mCompilation of \033[0m\033[31m$(notdir $<)\033[34m done.\033[0m"
	@$(CC) $(FLAG) -I $(INCLUDES) -c -MD $< -o $@
	@printf "\033[A\033[K"

-include $(DEPS)

norm:
	@$(NORM) $(FILES) $(HEADER)

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(DEPS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norm

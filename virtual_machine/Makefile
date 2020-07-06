NAME = corewar
CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR = ./inc

# .c files
MAIN_SRC = main.c

# .h files
INC_LIST = virtual_machine.h

# Libft variables

LIBFT_DIR = ../libft/
LIBFT_INC = $(LIBFT_DIR)includes
LIBFT = $(LIBFT_DIR)libft.a

# Sources variables
SRC_DIR = ./srcs/
SRC_LIST = $(MAIN_SRC)
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

# Objects variables
OBJ_DIR = ./objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# Dependencies variables

DEPS_DIR = ./deps/
DEPS_LIST = $(notdir $(patsubst %.c, %.d, $(SRC_LIST)))
DEPS = $(addprefix $(DEPS_DIR), $(DEPS_LIST))

INCLUDES = -I ./includes/ -I ./libft/includes

all: $(NAME)


$(NAME): $(LIBFT) $(OBJ_DIR) $(DEPS_DIR) $(OBJS) $(DEPS)
	 @$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	 @echo "\033[33mVM build!\033[0m"

$(OBJ_DIR):
	 @mkdir -p $(OBJ_DIR)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	 @echo "\033[34mCompilation of \033[0m\033[31m$(notdir $<)\033[34m done.\033[0m"
	 @$(CC) $(CFLAGS) -c -MD $(INCLUDES) $< -o $@
	 @printf "\033[A\033[K"
	 @mv $(OBJ_DIR)$*.d $(DEPS_DIR)

$(DEPS_DIR):
	 @mkdir -p $(DEPS_DIR)

$(DEPS):

-include $(wildcard $(DEPS))

$(LIBFT):
	 @make -C $(LIBFT_DIR)

clean:
	 @echo "\033[31mRemove objects and deps\033[0m"
	 @rm -rf $(OBJ_DIR)
	 @rm -rf $(DEPS_DIR)
	 @make clean -C $(LIBFT_DIR)

fclean: clean
	 @echo "\033[31mRemove project\033[0m"
	 @make fclean -C $(LIBFT_DIR)
	 @rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
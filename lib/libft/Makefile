# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luiza <luiza@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 17:11:20 by lukorman          #+#    #+#              #
#    Updated: 2025/03/11 19:42:57 by luiza            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                    config                                    #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR)
AR	= ar -rcs
RM	= rm -rf

# **************************************************************************** #
#                                    paths                                     #
# **************************************************************************** #

OBJ_DIR	= obj/
SRC_DIR	= src/
BIN_DIR	= bin/
INC_DIR	= include/

LIB_DIR	= $(SRC_DIR)libft/
GNL_DIR	= $(SRC_DIR)gnl/
PRINTF_DIR	= $(SRC_DIR)printf/

LIBFT_NAME	= $(BIN_DIR)libft.a

# **************************************************************************** #
#                                   files                                      #
# **************************************************************************** #

LIBFT_FILES	= $(wildcard $(LIB_DIR)ctype/*.c) \
			$(wildcard $(LIB_DIR)stdlib/*.c) \
			$(wildcard $(LIB_DIR)string/*.c) \
			$(wildcard $(LIB_DIR)unistd/*.c) \
			$(wildcard $(LIB_DIR)memory/*.c) \
			$(wildcard $(LIB_DIR)lists/*.c)
GNL_FILES	= $(wildcard $(GNL_DIR)/*.c)
PRINTF_FILES	= $(wildcard $(PRINTF_DIR)/*.c)

LIBFT_OBJS = $(patsubst $(LIB_DIR)%.c, $(OBJ_DIR)libft/%.o, $(LIBFT_FILES))
GNL_OBJS	= $(patsubst $(GNL_DIR)%.c, $(OBJ_DIR)gnl/%.o, $(GNL_FILES))
PRINTF_OBJS	= $(patsubst $(PRINTF_DIR)%.c, $(OBJ_DIR)printf/%.o, $(PRINTF_FILES))

ALL_OBJS = $(LIBFT_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

# **************************************************************************** #
#                              compile commands                                #
# **************************************************************************** #


COMPILE_LIBFT = $(AR) $(LIBFT_NAME) $(ALL_OBJS)

# **************************************************************************** #
#                                  targets                                     #
# **************************************************************************** #

all:$(LIBFT_NAME)

$(LIBFT_NAME): $(ALL_OBJS)
	mkdir -p $(BIN_DIR)
	$(COMPILE_LIBFT)

$(OBJ_DIR)libft/%.o: $(LIB_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)gnl/%.o: $(GNL_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)printf/%.o: $(PRINTF_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re

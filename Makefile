# **************************************************************************** #
#                               configuration                                  #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_INC)
CFLAGS_B	= -Wall -Wextra -Werror -I$(INC_BONUS) -I$(LIBFT_INC) -I$(MLX_INC)
RM			= rm -rf

# **************************************************************************** #
#                                directories                                   #
# **************************************************************************** #

SRC_DIR		= src/
SRC_D_BONUS	= src_bonus/
OBJ_DIR		= build/
OBJ_D_BONUS	= build_bonus/
INC_DIR		= include
INC_BONUS	= include_bonus
LIBFT_DIR	= lib/libft
LIBFT_INC	= $(LIBFT_DIR)/include
LIBFT_BIN	= $(LIBFT_DIR)/bin
MLX_DIR		= lib/minilibx-linux
MLX_INC		= $(MLX_DIR)

# **************************************************************************** #
#                                 libraries                                    #
# **************************************************************************** #

LIBFT	= $(LIBFT_BIN)/libft.a
MLX		= $(MLX_DIR)/libmlx.a
LIBS	= -L$(LIBFT_BIN) -L$(MLX_DIR) -lft -lmlx -lXext -lX11 -lm -lz

# **************************************************************************** #
#                                   files                                      #
# **************************************************************************** #

NAME		= cub3D

# mandatory
SRC			= $(shell find $(SRC_DIR) -name '*.c')
OBJ			= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))
HEADERS		= $(shell find $(INC_DIR) -name '*.h')

# bonus
SRC_BONUS	= $(shell find $(SRC_D_BONUS) -name '*.c')
OBJ_BONUS	= $(patsubst $(SRC_D_BONUS)%, $(OBJ_D_BONUS)%, $(SRC_BONUS:.c=.o))
HEADERS_B	= $(shell find $(INC_BONUS) -name '*.h')

# **************************************************************************** #
#                              compile commands                                #
# **************************************************************************** #

#mandatory
COMP		= $(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
COMP_OBJ	= $(CC) $(CFLAGS) -c $< -o $@

#bonus
COMP_BONUS	= $(CC) $(CFLAGS_B) $(OBJ_BONUS) $(LIBS) -o $(NAME)
COMP_OBJ_B	= $(CC) $(CFLAGS_B) -c $< -o $@

# **************************************************************************** #
#                                  targets                                     #
# **************************************************************************** #

all: $(NAME)

# mandatory
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(COMP_OBJ)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(COMP)
	@echo "./cub3d mandatory ready to use"

# submodules and libs
$(LIBFT_DIR)/Makefile $(MLX_DIR)/Makefile:
	@echo "Initializing submodules..."
	@git submodule update --init --recursive

$(LIBFT): $(LIBFT_DIR)/Makefile
	@$(MAKE) -C $(LIBFT_DIR) --silent

MLX_LOG	= $(OBJ_DIR)mlx.log

$(MLX): $(MLX_DIR)/Makefile
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) > $(MLX_LOG) 2>&1 \
		|| (cat $(MLX_LOG); exit 1)

# valgrind
LEAKS	:=	valgrind --leak-check=full --show-leak-kinds=all\
		--track-origins=yes --log-file=valgrind-out.txt --track-fds=yes

val_leaks: all
	@$(LEAKS) ./$(NAME) maps/open_map.cub
	@echo "./cub3d ready to use with valgrind"

# clean
clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJ_D_BONUS)
	@$(MAKE) clean -C $(LIBFT_DIR) --silent
	@echo "objects removed."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent
	@echo "'$(NAME)' removed."

# bonus
bonus: $(LIBFT) $(MLX) $(OBJ_BONUS)
	@$(COMP_BONUS)
	@echo "./cub3d bonus ready to use"

$(OBJ_D_BONUS)%.o: $(SRC_D_BONUS)%.c $(HEADERS_B)
	@mkdir -p $(dir $@)
	@$(COMP_OBJ_B)

re: fclean all

.PHONY: all clean fclean bonus re
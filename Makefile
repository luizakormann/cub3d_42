# **************************************************************************** #
#                               configuration                                  #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_INC)
RM		= rm -rf

# **************************************************************************** #
#                                directories                                   #
# **************************************************************************** #

SRC_DIR		= src/
OBJ_DIR		= build/
INC_DIR		= include
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

NAME	= cub3D
SRC		= $(shell find $(SRC_DIR) -name '*.c')
OBJ		= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))
HEADERS	= $(shell find $(INC_DIR) -name '*.h')

# **************************************************************************** #
#                              compile commands                                #
# **************************************************************************** #

COMP		= $(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
COMP_OBJ	= $(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #
#                                  targets                                     #
# **************************************************************************** #

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(COMP_OBJ)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(COMP)
	@echo "./cub3d ready to use"

$(LIBFT_DIR)/Makefile $(MLX_DIR)/Makefile:
	@echo "Initializing submodules..."
	@git submodule update --init --recursive

$(LIBFT): $(LIBFT_DIR)/Makefile
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(MLX):
	@$(MAKE) -C $(MLX_DIR) --silent

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR) --silent
	@echo "objects removed."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent
	@echo "'$(NAME)' removed."

re: fclean all

.PHONY: all clean fclean re
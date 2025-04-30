#! Variables

NAME		= cub3D
LIBFT_DIR	= libft/
LIBFT		= libft/libft.a
OBJ_DIR		= obj/
SRC_DIR		= src/
MLX_DIR		= minilibx-linux/
MLX			= minilibx-linux/libmlx.a
CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror -I/usr/include/ -Iminilibx-linux/ -Ilibft/
CFLAGS	+= -Iinclude/
DFLAGS	= -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

#! Sources

GAME_DIR	=	game_engine/
GAME		=	display mlx_management \

PARSE_DIR	=	parsing/
PARSE		=	check_mapfile get_data_map get_map get_data_map_utils \
				check_wall check_wall_utils \

STRUCT_DIR	=	struct/
STRUCT		=	struct_data struct_img struct_map struct_player struct_raycast \

UTILS_DIR	=	utils/
UTILS		=	error_handler \

SRC_FILES	=	main \
				$(addprefix $(GAME_DIR), $(GAME)) \
				$(addprefix $(PARSE_DIR), $(PARSE)) \
				$(addprefix $(STRUCT_DIR), $(STRUCT)) \
				$(addprefix $(UTILS_DIR), $(UTILS)) \

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#! Make

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR) --no-print-directory
	@echo "Compiling $(NAME)..."
	@$(CC) $(OBJS) $(MLX) $(LIBFT) $(DFLAGS) -o $(NAME)
	@echo "$(NAME) compiled!"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | obj_mkdir
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: all

clean:
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME) objects files cleaned!"

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo "$(NAME) removed!"

libft:
	@make -C $(LIBFT_DIR) --no-print-directory

mlx:
	@make -C $(MLX_DIR) --no-print-directory

obj_mkdir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(GAME_DIR)
	@mkdir -p $(OBJ_DIR)$(PARSE_DIR)
	@mkdir -p $(OBJ_DIR)$(STRUCT_DIR)
	@mkdir -p $(OBJ_DIR)$(UTILS_DIR)

norm:
	@norminette src/ include/ -o

re: fclean all
	@echo "Cleaned and rebuild $(NAME) from zero!"

.PHONY: all bonus clean fclean libft mlx norm re

NAME = rtv1
RM = /bin/rm -f

FLAGS = -Wall -Wextra -Werror

# rtv1
FILES = main image hooks error parser
INCLUDE = -I ./includes/
HEADER = ./includes/rtv1.h
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/
CFILES = $(patsubst %, $(SRC_DIR)%.c, $(FILES))
OFILES = $(patsubst %, $(OBJ_DIR)%.o, $(FILES))

# libft lib
LFT_DIR = ./libft/
LFT_LIB = $(addprefix $(LFT_DIR), ft.a)
LFT_INC = -I $(LFT_DIR)/include/
LFT_LINK = -L $(LFT_DIR) -l ft

#minilibx link
MINILIBX_DIR = ./minilibx/
MINILIBX_LINK = -L $(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(LFT_LIB) $(MLX_LIB) $(NAME)

$(MLX_LIB): 
	@make -C ./minilibx_macos

$(LFT_LIB):
	make -C $(LFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo [INFO] rtv1 Object Files Directory Created

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	gcc $(FLAGS) $(INCLUDE) $(LFT_INC) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OFILES)
	@make -C $(MINILIBX_DIR)
	@gcc $(FLAGS) $(OFILES) $(LFT_LINK) $(MINILIBX_LINK) -o $(NAME)
	@echo [INFO] rtv1 Binary Created

clean:
	@rm -rf $(OBJ_DIR)
	@echo [INFO] rtv1 Object Files Directory Destroyed
	@make -C $(LFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@echo [INFO] rtv1 Binary Destroyed
	@make -C $(LFT_DIR) fclean
	@make -C $(MINILIBX_DIR) clean

re: fclean all

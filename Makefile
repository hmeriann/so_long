NAME	= so_long

NAM_BNS	= so_long_bonus

FLAGS	= -Wall -Wextra -Werror
MLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC		= ./src/ft_solong.c	./src/ft_strnstr.c	./src/ft_prepare_map.c	./src/ft_validate_map.c\
		./src/ft_check_map.c	./src/ft_use_mlx_to_play.c	./src/ft_key_hook.c	./src/ft_play_the_game.c\

SRC_BNS	= ./src_bns/ft_solong_bns.c	./src_bns/ft_strnstr_bns.c	./src_bns/ft_prepare_map_bns.c	./src_bns/ft_validate_map_bns.c\
		./src_bns/ft_check_map_bns.c	./src_bns/ft_use_mlx_bns.c	./src_bns/ft_key_hook_bns.c	./src_bns/ft_play_the_game_bns.c\
		./src_bns/ft_move_left_right.c	./src_bns/ft_make_message.c	./src_bns/ft_anima.c\
		./src_bns/ft_put_images.c	./src_bns/ft_patrol.c	./src_bns/ft_re_render_map.c\

OBJ		= $(SRC:.c=.o)

OBJ_BNS	= $(SRC_BNS:.c=.o)

HEAD	= so_long.h

HEA_BNS	= so_long_bonus.h

BLUE	= \033[36m
YEL		= \033[33m
DEF		= \033[0m

LIB		= libft/libft.a

all:	$(NAME)

$(NAME): $(OBJ) $(HEAD)
		@echo "\n$(NAME): $(BLUE)OBJ is created$(DEF)"
		@$(MAKE) -C libft
		@$(MAKE) -C ./mlx
		@gcc $(FLAGS) $(OBJ) $(LIB) $(MLX) -o $@
		@echo "$(NAME): $(BLUE)Executable file so_long is created$(DEF)"

bonus:	$(NAM_BNS)

$(NAM_BNS): $(OBJ_BNS) $(HEA_BNS)
		@echo "\n$(NAM_BNS): $(BLUE)OBJ_BNS is created$(DEF)"
		@$(MAKE) -C libft
		@$(MAKE) -C ./mlx
		@gcc $(FLAGS) $(OBJ_BNS) $(LIB) $(MLX) -o $@
		@echo "$(NAM_BNS): $(BLUE)Executable file so_long_bonus is created$(DEF)"

%.o: %.c
		@echo "$(BLUE)❱❱❱❱❱❱$(DEF)\c"
		@$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
		@$(MAKE) clean -C libft
		@$(MAKE) clean -C ./mlx
		@rm -f $(OBJ) $(OBJ_BNS)
		@echo "$(NAME) $(NAM_BNS): $(YEL)OBJ cleaned$(DEF)"

fclean:	clean
		@$(MAKE) clean -C libft
		@$(MAKE) clean -C./mlx
		@rm -f $(NAME) $(NAM_BNS)
		@echo "$(NAME) $(NAM_BNS): $(BLUE)Executables cleaned$(DEF)"

re:		fclean all

norm:
		norminette $(SRC) $(SRC_BNS) so_long.h so_long_bonus.h

.PHONY:	all bonus clean fclean re

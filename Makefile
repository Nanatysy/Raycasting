NAME = cub3D
SRCC = elements_pars_extra.c elements_pars.c error_extra.c errors.c \
exit.c get_addr.c get_next_line.c hex.c image.c input_check.c main.c \
map_pars_extra.c map_pars.c parser.c player.c pre_render_and_color.c \
ray.c save.c sprite_list_func.c sprite_text.c sprite.c walls.c walls_extra.c \
sprite_angle.c resolution.c
SRCO = $(SRCC:%.c=%.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO) ./libft/libft.a libmlx.dylib
	gcc $(FLAGS) $^ -L./libft -L./mlx libmlx.dylib -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c ft_cub3d.h
	gcc $(FLAGS) -c $<

./libft/libft.a: 
	make bonus -C ./libft

libmlx.dylib:
	make -C ./mlx
	cp mlx/libmlx.dylib ./

clean:
	make clean -C ./libft
	make clean -C ./mlx
	rm -rf $(SRCO)

bonus: all

fclean: clean
	make fclean -C ./libft
	rm -rf libmlx.dylib
	rm -rf $(NAME)

re: fclean all
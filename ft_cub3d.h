#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include "./mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			distance;
	double			angle;
	double			l_angle;
	double			r_angle;
	double			column_mult_by_bpp;
	int				half_height;
	int				height;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_ray
{
	double			pov;
	double			w_angle;
	double			px;
	double			py;
	double			ax;
	double			ay;
	double			step_x;
	double			step_y;
	double			wall_x_h;
	double			wall_y_h;
	double			wall_x_v;
	double			wall_y_v;
	double			res_x;
	double			res_y;
	double			shift_y;
	double			shift_x;
	double			distance;
	double			diff_cosinus;
	double			tangens;
	int				flag;
	int				cross;
	int				block;
	int				wall;
	int				not_a_wall;
	double			fov;
}					t_ray;

typedef struct		s_map
{
	t_list			*tmap;
	t_sprite		*tsprite;
	int				pp_width;
	int				pp_height;
	int				map_height;
	int				map_width;
	char			*north_text;
	char			*east_text;
	char			*south_text;
	char			*west_text;
	char			*sprite_text;
	int				floor;
	int				ceilling;
	char			**map;
	int				flag;
	int				count;
	int				max_pp_height;
	int				max_pp_width;
	int				min_pp_height;
	int				min_pp_width;
	int				half_pp_height;
	double			len;
	double			angle_step;
}					t_map;

typedef struct		s_image
{
	void			*image;
	char			*addr;
	int				bits_per_pixel;
	int				bytes_per_pixel;
	int				line_length;
	int				endian;
	int				column_mult_by_bpp;
	int				height_mult_by_ll;
}					t_image;

typedef struct		s_texture
{
	void			*text;
	char			*addr;
	char			*dst;
	double			wall_step;
	double			pixel_height;
	int				column_mult_by_bpp;
	int				bits_per_pixel;
	int				bytes_per_pixel;
	int				line_length;
	int				width;
	int				height;
	int				half_height;
	int				endian;
}					t_texture;

typedef struct		s_all
{
	void			*mlx;
	void			*mlx_win_maze;
	t_image			*img_maze;
	t_texture		*north;
	t_texture		*south;
	t_texture		*west;
	t_texture		*east;
	t_texture		*sprite;
	t_ray			*ray;
	t_map			*map;
	int				flag;
}					t_all;

t_sprite			*spr_new(double x, double y);
double				angle_calc(double px, double py, double sx, double sy);
void				ft_distance_calculation(t_ray *ray, char **map, \
int height, int width);
void				ft_find_player_coord(t_ray *ray, char **map, int height);
void				ft_horisontal_cross(t_ray *ray, char **map, \
int height, int width);
void				ft_vertical_cross(t_ray *ray, char **map, int height, \
int width);
void				ft_basic_calc(t_ray *ray, char **map, int height, \
int width);
void				ft_find_pov(t_ray *ray, char **map);
void				ft_player_coord_change(t_ray *ray, int keycode, char **map);
void				ft_player_move(t_ray *ray, char **map, int flag);
void				my_mlx_pixel_put(t_image *img, int color);
void				display_maze(t_all *all, int flag);
void				angle_recalculation(t_ray *ray);
void				pre_render_calculation(t_all *all);
void				draw_sprite(t_all *all, t_sprite *cur);
void				draw_walls(t_all *all);
void				count_sprite_column(t_all *all, t_sprite *cur);
void				ft_sprite_color_first(t_all *all, int j, \
t_sprite *cur);
void				ft_sprite_color_second(t_all *all, int j, \
t_sprite *cur);
void				ft_sprite_show(t_sprite *spr);
void				ft_extra_draw(t_all *all);
void				ft_south_wall(t_all *all);
void				ft_north_wall(t_all *all);
void				ft_west_wall(t_all *all);
void				ft_east_wall(t_all *all);
void				count_wall_column(t_all *all);
void				count_height_step(t_all *all);
void				ft_get_addr(t_all *all);
void				ft_open_textures(t_all *all);
void				ft_sprite_text(t_all *all);
void				mult_inclution(int flag);
void				extra_characters(int flag);
void				wrong_path(int flag);
void				miss_param(int flag);
void				print_error(char *line, t_all *all, int	error_flag);
void				ft_check_element(char *line, t_all *all);
void				get_map_info(int fd, char *line, t_all *all);
void				ft_north(char *str, char *line, t_all *all);
void				ft_east(char *str, char *line, t_all *all);
void				ft_south(char *str, char *line, t_all *all);
void				ft_west(char *str, char *line, t_all *all);
void				ft_resolution(char *str, char *line, t_all *all);
void				ft_floor(char *str, char *line, t_all *all);
void				ft_ceilling(char *str, char *line, t_all *all);
void				ft_sprite(char *str, char *line, t_all *all);
void				ft_check_char(t_list **tmap, t_all *all);
void				ft_is_it_close(char **map, int height, t_all *all);
void				ft_check_player(char **map, int height, t_all *all);
void				ft_map_er(t_all *all, char *line);
void				ft_malloc_er(t_all *all, char *line, int flag);
void				ft_list_fill(t_all *all, char *line, int *end);
void				get_info(char *str, t_all *all);
void				resolution_height_recalculation(t_all *all);
void				resolution_width_recalculation(t_all *all);
void				ft_miss_element(t_all *all, char *line);
void				ft_trash_error(t_all *all, char *line);
void				pre_map_errors(t_all *all, char *line);
void				free_map_struct(t_map *file);
void				my_exit(t_all *all);
void				free_all(t_all *all);
void				ft_render_maze_frame(t_all *all);
void				ft_wall_color_calculation(t_all *all);
void				ft_byte_shift(int num, unsigned char *str);
void				save(t_all *all);
void				ft_put_bmpheader(int fd, t_all *all);
void				sprite_lst(t_all *all, int i, int j);
void				spr_push_back(t_sprite *head, double x, double y, \
t_all *all);
void				sprite_distance_calc(t_all *all);
void				sprite_sort(t_sprite **head);
void				sprite_swap(t_sprite **cur, t_sprite *next, t_sprite \
**head, int *flag);
void				sprite_collection(t_all *all);
void				ft_malloc(t_all *all);
char				**map_list_to_char(t_list **s, t_all *all);
int					ft_close(t_all *all);
int					key_hook(int keycode, t_all *all);
int					ft_hex(int r, int g, int b);
int					ft_spaces_skip(char **s);
int					ft_is_it_map_yet(char *s1, char *s2);
int					ft_check_map_line(char *s1, char *s2);
int					ft_input_check(int argc, char **argv);
int					ft_first_error(int flag);
int					get_next_line(char **line, int fd);
int					sprite_count(t_sprite *spr);
int					angle_check(double ray_ang, t_sprite *cur, double dist);

#endif

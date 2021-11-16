#include "ft_cub3d.h"

void	my_mlx_pixel_put(t_image *img, int color)
{
	char	*dst;

	dst = img->addr + (img->height_mult_by_ll + img->column_mult_by_bpp);
	*(unsigned int*)dst = color;
}

void	ft_render_maze_frame(t_all *all)
{
	int			i;

	i = -1;
	sprite_distance_calc(all);
	sprite_sort(&all->map->tsprite);
	angle_recalculation(all->ray);
	while (++i < all->map->pp_width)
	{
		all->img_maze->column_mult_by_bpp = i * all->img_maze->bytes_per_pixel;
		all->img_maze->height_mult_by_ll = 0;
		pre_render_calculation(all);
		count_wall_column(all);
		draw_walls(all);
		ft_extra_draw(all);
	}
}

int		ft_close(t_all *all)
{
	mlx_destroy_window(all->mlx, all->mlx_win_maze);
	my_exit(all);
	return (0);
}

int		key_hook(int keycode, t_all *all)
{
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 123)
			all->ray->pov -= 0.0523599;
		else
			all->ray->pov += 0.0523599;
		ft_render_maze_frame(all);
		mlx_put_image_to_window(all->mlx, all->mlx_win_maze, \
		all->img_maze->image, 0, 0);
		mlx_do_sync(all->mlx);
	}
	if ((keycode >= 0 && keycode < 3) || keycode == 13)
	{
		ft_player_coord_change(all->ray, keycode, all->map->map);
		ft_render_maze_frame(all);
		mlx_put_image_to_window(all->mlx, all->mlx_win_maze, \
		all->img_maze->image, 0, 0);
		mlx_do_sync(all->mlx);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(all->mlx, all->mlx_win_maze);
		my_exit(all);
	}
	return (0);
}

void	display_maze(t_all *all, int flag)
{
	all->mlx_win_maze = mlx_new_window(all->mlx, all->map->pp_width, \
	all->map->pp_height, "hella maze");
	all->img_maze->image = mlx_new_image(all->mlx, all->map->pp_width, \
	all->map->pp_height);
	all->img_maze->addr = mlx_get_data_addr(all->img_maze->image, \
	&all->img_maze->bits_per_pixel, &all->img_maze->line_length, \
	&all->img_maze->endian);
	all->img_maze->bytes_per_pixel = all->img_maze->bits_per_pixel / 8;
	ft_open_textures(all);
	ft_sprite_text(all);
	ft_render_maze_frame(all);
	if (flag == 1)
	{
		mlx_put_image_to_window(all->mlx, all->mlx_win_maze, \
		all->img_maze->image, 0, 0);
		mlx_hook(all->mlx_win_maze, 17, 0L, ft_close, all);
		mlx_hook(all->mlx_win_maze, 2, 1L << 0, key_hook, all);
		mlx_loop(all->mlx);
	}
	else
		save(all);
}

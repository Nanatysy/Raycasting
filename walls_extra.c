#include "ft_cub3d.h"

void	count_wall_column(t_all *all)
{
	all->south->column_mult_by_bpp = (int)round((all->ray->res_x - (int)\
	(all->ray->res_x / all->ray->block) * all->ray->block) / all->ray->block * \
	(all->south->width - 1)) * all->south->bytes_per_pixel;
	all->north->column_mult_by_bpp = (int)round(((int)((all->ray->res_x / \
	all->ray->block) + 1) * all->ray->block - all->ray->res_x) / \
	all->ray->block * (all->north->width - 1)) * all->north->bytes_per_pixel;
	all->west->column_mult_by_bpp = (int)round((all->ray->res_y - (int)\
	(all->ray->res_y / all->ray->block) * all->ray->block) / all->ray->block * \
	(all->west->width - 1)) * all->west->bytes_per_pixel;
	all->east->column_mult_by_bpp = (int)round(((int)((all->ray->res_y / \
	all->ray->block) + 1) * all->ray->block - all->ray->res_y) / \
	all->ray->block * (all->east->width - 1)) * all->east->bytes_per_pixel;
}

void	count_height_step(t_all *all)
{
	double	tmp;

	if (all->ray->wall < all->map->pp_height)
	{
		all->north->pixel_height = 0;
		all->south->pixel_height = 0;
		all->west->pixel_height = 0;
		all->east->pixel_height = 0;
	}
	else
	{
		tmp = ((double)(all->ray->wall - all->map->pp_height) / 2) \
		/ all->ray->wall;
		all->north->pixel_height = tmp * all->north->height;
		all->south->pixel_height = tmp * all->south->height;
		all->west->pixel_height = tmp * all->west->height;
		all->east->pixel_height = tmp * all->east->height;
	}
	all->north->wall_step = (double)(all->north->height - 1) / all->ray->wall;
	all->south->wall_step = (double)(all->south->height - 1) / all->ray->wall;
	all->west->wall_step = (double)(all->west->height - 1) / all->ray->wall;
	all->east->wall_step = (double)(all->east->height - 1) / all->ray->wall;
}

void	count_sprite_column(t_all *all, t_sprite *cur)
{
	if (angle_check(all->ray->w_angle, cur, all->ray->distance) / 10 == 1)
		cur->column_mult_by_bpp = (1 - ((double)(all->ray->w_angle - \
		cur->l_angle)) / \
		(cur->r_angle - cur->l_angle)) * (all->sprite->width - 1);
	else
	{
		if (all->ray->w_angle > M_PI * 2 - all->ray->fov)
			cur->column_mult_by_bpp = (1 - (((double)(all->ray->w_angle - \
			cur->l_angle)) / (M_PI * 2 - cur->l_angle + cur->r_angle))) * \
			(all->sprite->width - 1);
		else
			cur->column_mult_by_bpp = (1 - (((double)(M_PI * 2 + \
			all->ray->w_angle - cur->l_angle)) / (M_PI * 2 - \
			cur->l_angle + cur->r_angle))) * (all->sprite->width - 1);
	}
	cur->column_mult_by_bpp = (int)round(cur->column_mult_by_bpp) * \
	all->sprite->bytes_per_pixel;
}

void	draw_walls(t_all *all)
{
	int	j;

	j = 0;
	while (j < all->map->pp_height)
	{
		if (j < all->ray->not_a_wall)
			my_mlx_pixel_put(all->img_maze, all->map->ceilling);
		else if (j < all->ray->not_a_wall + all->ray->wall)
			ft_wall_color_calculation(all);
		else
			my_mlx_pixel_put(all->img_maze, all->map->floor);
		j++;
		all->img_maze->height_mult_by_ll += all->img_maze->line_length;
	}
}

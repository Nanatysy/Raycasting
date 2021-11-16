#include "ft_cub3d.h"

void	ft_horisontal_cross(t_ray *ray, char **map, int height, int width)
{
	int	coord_x;
	int	coord_y;

	ray->shift_y = (ray->w_angle < M_PI) ? ray->block : -0.0000001;
	ray->flag = (ray->shift_y != ray->block) ? -1 : 1;
	ray->ay = (int)(ray->py / ray->block) * ray->block + ray->shift_y;
	ray->ax = ray->px - (ray->py - ray->ay) / ray->tangens;
	ray->step_y = (ray->shift_y == ray->block) ? ray->block : -ray->block;
	ray->step_x = ray->block / ray->tangens * ray->flag;
	while ((int)(ray->ay / ray->block) < height - 1 && (int)(ray->ay / \
	ray->block) > 0)
	{
		coord_x = (int)(ray->ax / ray->block);
		coord_y = (int)(ray->ay / ray->block);
		if ((coord_x >= 0 && coord_x < width) && (coord_y >= 0 && \
		coord_y < height))
			if (map[coord_y][coord_x] == '1')
				break ;
		ray->ax += ray->step_x;
		ray->ay += ray->step_y;
	}
	ray->wall_x_h = ray->ax;
	ray->wall_y_h = ray->ay;
}

void	ft_vertical_cross(t_ray *ray, char **map, int height, int width)
{
	int	coord_x;
	int	coord_y;

	ray->shift_x = (ray->w_angle > M_PI_2 && ray->w_angle < M_PI_2 * 3) \
	? -0.0000001 : ray->block;
	ray->flag = (ray->shift_x != ray->block) ? -1 : 1;
	ray->ax = (int)(ray->px / ray->block) * ray->block + ray->shift_x;
	ray->ay = ray->py - (ray->px - ray->ax) * ray->tangens;
	ray->step_x = (ray->shift_x == ray->block) ? ray->block : -ray->block;
	ray->step_y = ray->block * ray->tangens * ray->flag;
	while ((int)(ray->ax / ray->block) < width - 1 && (int)(ray->ax / \
	ray->block) > 0)
	{
		coord_x = ray->ax / ray->block;
		coord_y = ray->ay / ray->block;
		if ((coord_x >= 0 && coord_x < width) && (coord_y >= 0 && \
		coord_y < height))
			if (map[coord_y][coord_x] == '1')
				break ;
		ray->ax += ray->step_x;
		ray->ay += ray->step_y;
	}
	ray->wall_x_v = ray->ax;
	ray->wall_y_v = ray->ay;
}

void	ft_basic_calc(t_ray *ray, char **map, int height, int width)
{
	double	vector_hor;
	double	vector_ver;

	ft_horisontal_cross(ray, map, height, width);
	ft_vertical_cross(ray, map, height, width);
	vector_hor = sqrt(pow(ray->wall_x_h - ray->px, 2) + pow(ray->wall_y_h \
	- ray->py, 2));
	vector_ver = sqrt(pow(ray->wall_x_v - ray->px, 2) + pow(ray->wall_y_v \
	- ray->py, 2));
	if (vector_hor < vector_ver)
	{
		ray->res_x = ray->wall_x_h;
		ray->res_y = ray->wall_y_h;
		ray->cross = 1;
	}
	else
	{
		ray->res_x = ray->wall_x_v;
		ray->res_y = ray->wall_y_v;
		ray->cross = -1;
	}
}

void	ft_distance_calculation(t_ray *ray, char **map, int height, int width)
{
	if (ray->w_angle == M_PI_2 || ray->w_angle == M_PI_2 * 3)
	{
		ft_horisontal_cross(ray, map, height, width);
		ray->cross = 1;
		ray->res_x = ray->wall_x_h;
		ray->res_y = ray->wall_y_h;
	}
	else if (ray->w_angle == M_PI || ray->w_angle == M_PI * 2 || \
	ray->w_angle == 0)
	{
		ft_vertical_cross(ray, map, height, width);
		ray->cross = -1;
		ray->res_x = ray->wall_x_v;
		ray->res_y = ray->wall_y_v;
	}
	else
		ft_basic_calc(ray, map, height, width);
	ray->distance = sqrt(pow(ray->res_x - ray->px, 2) + \
	pow(ray->res_y - ray->py, 2));
}

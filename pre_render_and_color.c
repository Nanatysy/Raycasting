/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render_and_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:33:53 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/25 13:06:09 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	angle_recalculation(t_ray *ray)
{
	if (ray->pov < 0)
		ray->pov += M_PI * 2;
	if (ray->pov > M_PI * 2)
		ray->pov -= M_PI * 2;
	ray->w_angle = ray->pov - ray->fov / 2;
}

void	pre_render_calculation(t_all *all)
{
	double	proportion;

	all->ray->w_angle += all->map->angle_step;
	all->ray->diff_cosinus = cos(all->ray->w_angle - all->ray->pov);
	if (all->ray->w_angle < 0)
		all->ray->w_angle += M_PI * 2;
	if (all->ray->w_angle > M_PI * 2)
		all->ray->w_angle -= M_PI * 2;
	all->ray->tangens = tan(all->ray->w_angle);
	ft_distance_calculation(all->ray, all->map->map, all->map->map_height, \
	all->map->map_width);
	proportion = all->map->len / (all->ray->distance * (all->ray->block / 2) * \
	all->ray->diff_cosinus);
	all->ray->wall = (int)round(proportion * all->map->pp_width);
	all->ray->not_a_wall = (all->map->pp_height - all->ray->wall) / 2;
	count_height_step(all);
}

void	ft_wall_color_calculation(t_all *all)
{
	if (all->ray->cross == 1 && all->ray->py < all->ray->res_y)
		ft_south_wall(all);
	else if (all->ray->cross == -1 && all->ray->px > all->ray->res_x)
		ft_west_wall(all);
	else if (all->ray->cross == 1 && all->ray->py > all->ray->res_y)
		ft_north_wall(all);
	else
		ft_east_wall(all);
}

void	ft_extra_draw(t_all *all)
{
	t_sprite	*tmp;

	tmp = all->map->tsprite;
	while (tmp)
	{
		if (angle_check(all->ray->w_angle, tmp, all->ray->distance))
			draw_sprite(all, tmp);
		tmp = tmp->next;
	}
}

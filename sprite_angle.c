#include "ft_cub3d.h"

int	angle_check(double ray_ang, t_sprite *cur, double dist)
{
	if (cur->l_angle < cur->r_angle)
	{
		if (ray_ang >= cur->l_angle && ray_ang <= cur->r_angle \
		&& cur->distance < dist)
			return (11);
		return (0);
	}
	else
	{
		if (((ray_ang >= cur->l_angle && ray_ang <= M_PI * 2) || \
		(ray_ang <= cur->r_angle && ray_ang >= 0)) && cur->distance < dist)
			return (21);
		return (0);
	}
}

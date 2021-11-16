#include "ft_cub3d.h"

void	ft_find_player_coord(t_ray *ray, char **map, int hight)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	while (j < hight)
	{
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'E' \
			|| map[j][i] == 'W')
			{
				x = i;
				y = j;
			}
			i++;
		}
		i = 0;
		j++;
	}
	ray->px = x * ray->block + ray->block / 2;
	ray->py = y * ray->block + ray->block / 2;
}

void	ft_find_pov(t_ray *ray, char **map)
{
	int	i;
	int	j;

	i = ray->px / ray->block;
	j = ray->py / ray->block;
	if (map[j][i] == 'N')
		ray->pov = M_PI_2 * 3;
	else if (map[j][i] == 'E')
		ray->pov = 0;
	else if (map[j][i] == 'S')
		ray->pov = M_PI_2;
	else
		ray->pov = M_PI;
}

void	ft_player_move(t_ray *ray, char **map, int flag)
{
	int	x;
	int	y;

	if (flag == 1 || flag == -1)
	{
		x = (int)((ray->px + 5 * cos(ray->pov + M_PI_2) * flag) / ray->block);
		y = (int)((ray->py + 5 * sin(ray->pov + M_PI_2) * flag) / ray->block);
		if (map[y][x] != '1' && map[y][x] != '2')
		{
			ray->px += 5 * cos(ray->pov + M_PI_2) * flag;
			ray->py += 5 * sin(ray->pov + M_PI_2) * flag;
		}
	}
	else
	{
		flag /= 2;
		y = (int)((ray->py + 5 * sin(ray->pov) * flag) / ray->block);
		x = (int)((ray->px + 5 * cos(ray->pov) * flag) / ray->block);
		if (map[y][x] != '1' && map[y][x] != '2')
		{
			ray->px += 5 * cos(ray->pov) * flag;
			ray->py += 5 * sin(ray->pov) * flag;
		}
	}
}

void	ft_player_coord_change(t_ray *ray, int keycode, char **map)
{
	int	flag;

	if (keycode == 0)
		flag = -1;
	else if (keycode == 2)
		flag = 1;
	else if (keycode == 13)
		flag = 2;
	else
		flag = -2;
	ft_player_move(ray, map, flag);
}

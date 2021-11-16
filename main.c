#include "ft_cub3d.h"

void	ft_malloc(t_all *all)
{
	if (!(all->map = malloc(sizeof(t_map))))
		my_exit(all);
	all->flag += 1;
	all->map->flag = 0;
	if (!(all->ray = malloc(sizeof(t_ray))))
		my_exit(all);
	all->flag += 2;
	if (!(all->img_maze = malloc(sizeof(t_image))))
		my_exit(all);
	all->flag += 4;
}

int		main(int argc, char **argv)
{
	t_all	*all;
	int		flag;

	if (!(flag = ft_input_check(argc, argv)))
		return (0);
	if (!(all = malloc(sizeof(t_all))))
		return (0);
	all->flag = 0;
	ft_malloc(all);
	all->mlx = mlx_init();
	mlx_get_screen_size(all->mlx, &all->map->max_pp_width, \
	&all->map->max_pp_height);
	all->map->min_pp_height = 320;
	all->map->min_pp_width = 320;
	all->ray->fov = M_PI / 3;
	all->ray->block = 64;
	get_info(argv[1], all);
	all->map->len = (all->map->pp_width / 2) / tan(all->ray->fov / 2);
	all->map->angle_step = all->ray->fov / all->map->pp_width;
	all->map->half_pp_height = all->map->pp_height / 2;
	ft_find_player_coord(all->ray, all->map->map, all->map->map_height);
	ft_find_pov(all->ray, all->map->map);
	display_maze(all, flag);
	free_all(all);
	return (0);
}

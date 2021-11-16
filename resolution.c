#include "ft_cub3d.h"

void	resolution_height_recalculation(t_all *all)
{
	if (all->map->pp_height > all->map->max_pp_height)
		all->map->pp_height = all->map->max_pp_height;
	else if (all->map->pp_height < all->map->min_pp_height)
		all->map->pp_height = all->map->min_pp_height;
}

void	resolution_width_recalculation(t_all *all)
{
	if (all->map->pp_width > all->map->max_pp_width)
		all->map->pp_width = all->map->max_pp_width;
	else if (all->map->pp_width < all->map->min_pp_width)
		all->map->pp_width = all->map->min_pp_width;
}

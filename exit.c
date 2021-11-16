#include "ft_cub3d.h"

void	tsprite_free(t_sprite *spr)
{
	t_sprite	*tmp;

	while (spr)
	{
		tmp = spr->next;
		free(spr);
		spr = tmp;
	}
}

void	free_map_struct(t_map *file)
{
	if (file->flag & 2)
		free(file->north_text);
	if (file->flag & 4)
		free(file->east_text);
	if (file->flag & 8)
		free(file->south_text);
	if (file->flag & 16)
		free(file->west_text);
	if (file->flag & 32)
		free(file->sprite_text);
	if (file->flag & 256)
		ft_lstclear(&file->tmap, free);
	if (file->flag & 512)
	{
		file->count--;
		while (file->count >= 0)
			free(file->map[file->count--]);
		free(file->map);
	}
	if (file->flag & 1024)
		tsprite_free(file->tsprite);
	free(file);
}

void	my_exit(t_all *all)
{
	if (all->flag & 1)
		free_map_struct(all->map);
	if (all->flag & 2)
		free(all->ray);
	if (all->flag & 4)
		free(all->img_maze);
	if (all->flag & 8)
		free(all->north);
	if (all->flag & 16)
		free(all->east);
	if (all->flag & 32)
		free(all->south);
	if (all->flag & 64)
		free(all->west);
	if (all->flag & 128)
		free(all->sprite);
	free(all);
	exit(0);
}

void	free_all(t_all *all)
{
	if (all->flag & 1)
		free_map_struct(all->map);
	if (all->flag & 2)
		free(all->ray);
	if (all->flag & 4)
		free(all->img_maze);
	if (all->flag & 8)
		free(all->north);
	if (all->flag & 16)
		free(all->east);
	if (all->flag & 32)
		free(all->south);
	if (all->flag & 64)
		free(all->west);
	if (all->flag & 128)
		free(all->sprite);
	free(all);
}

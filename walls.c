#include "ft_cub3d.h"

void	ft_open_textures(t_all *all)
{
	if (!(all->south = malloc(sizeof(t_texture))))
		my_exit(all);
	all->flag += 8;
	if (!(all->north = malloc(sizeof(t_texture))))
		my_exit(all);
	all->flag += 16;
	if (!(all->east = malloc(sizeof(t_texture))))
		my_exit(all);
	all->flag += 32;
	if (!(all->west = malloc(sizeof(t_texture))))
		my_exit(all);
	all->flag += 64;
	all->south->text = mlx_xpm_file_to_image(all->mlx, all->map->south_text, \
	&all->south->width, &all->south->height);
	all->west->text = mlx_xpm_file_to_image(all->mlx, all->map->west_text, \
	&all->west->width, &all->west->height);
	all->east->text = mlx_xpm_file_to_image(all->mlx, all->map->east_text, \
	&all->east->width, &all->east->height);
	all->north->text = mlx_xpm_file_to_image(all->mlx, all->map->north_text, \
	&all->north->width, &all->north->height);
	if (all->south->text == NULL || all->north->text == NULL || \
	all->west->text == NULL || all->east->text == NULL)
		my_exit(all);
	ft_get_addr(all);
}

void	ft_south_wall(t_all *all)
{
	int		pixel;
	char	*dst;

	all->south->pixel_height += all->south->wall_step;
	dst = all->south->addr + ((int)round(all->south->pixel_height) * \
	all->south->line_length + all->south->column_mult_by_bpp);
	pixel = *(unsigned int *)dst;
	if (pixel < 0)
		pixel = 0;
	my_mlx_pixel_put(all->img_maze, pixel);
}

void	ft_north_wall(t_all *all)
{
	int		pixel;
	char	*dst;

	all->north->pixel_height += all->north->wall_step;
	dst = all->north->addr + ((int)round(all->north->pixel_height) * \
	all->north->line_length + all->north->column_mult_by_bpp);
	pixel = *(unsigned int *)dst;
	if (pixel < 0)
		pixel = 0;
	my_mlx_pixel_put(all->img_maze, pixel);
}

void	ft_west_wall(t_all *all)
{
	int		pixel;
	char	*dst;

	all->west->pixel_height += all->west->wall_step;
	dst = all->west->addr + ((int)round(all->west->pixel_height) * \
	all->west->line_length + all->west->column_mult_by_bpp);
	pixel = *(unsigned int *)dst;
	if (pixel < 0)
		pixel = 0;
	my_mlx_pixel_put(all->img_maze, pixel);
}

void	ft_east_wall(t_all *all)
{
	int		pixel;
	char	*dst;

	all->east->pixel_height += all->east->wall_step;
	dst = all->east->addr + ((int)round(all->east->pixel_height) * \
	all->east->line_length + all->east->column_mult_by_bpp);
	pixel = *(unsigned int *)dst;
	if (pixel < 0)
		pixel = 0;
	my_mlx_pixel_put(all->img_maze, pixel);
}

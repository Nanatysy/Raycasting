/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:36:27 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/25 13:13:49 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_sprite_text(t_all *all)
{
	if (!(all->sprite = malloc(sizeof(t_texture))))
		my_exit(all);
	all->flag += 128;
	all->sprite->text = mlx_xpm_file_to_image(all->mlx, all->map->sprite_text, \
	&all->sprite->width, &all->sprite->height);
	if (all->sprite->text == NULL)
		my_exit(all);
	all->sprite->addr = mlx_get_data_addr(all->sprite->text, \
	&all->sprite->bits_per_pixel, &all->sprite->line_length, \
	&all->sprite->endian);
	all->sprite->bytes_per_pixel = all->sprite->bits_per_pixel / 8;
	all->sprite->half_height = all->sprite->height / 2;
}

void	ft_sprite_color_first(t_all *all, int j, t_sprite *cur)
{
	double	height;
	int		pixel;
	char	*dst;

	height = all->sprite->half_height - ((double)(all->map->half_pp_height - \
	j) / cur->height) * (all->sprite->height - 1);
	dst = all->sprite->addr + ((int)round(height) * all->sprite->line_length + \
	(int)round(cur->column_mult_by_bpp));
	pixel = *(unsigned int*)dst;
	if (pixel >= 0)
		my_mlx_pixel_put(all->img_maze, pixel);
}

void	ft_sprite_color_second(t_all *all, int j, t_sprite *cur)
{
	double	height;
	int		pixel;
	char	*dst;

	height = (int)round(all->sprite->half_height) + ((double)(j - \
	all->map->half_pp_height) / cur->height) * (all->sprite->height - 1);
	dst = all->sprite->addr + ((int)round(height) * all->sprite->line_length + \
	(int)round(cur->column_mult_by_bpp));
	pixel = *(unsigned int*)dst;
	if (pixel >= 0)
		my_mlx_pixel_put(all->img_maze, pixel);
}

void	draw_sprite(t_all *all, t_sprite *cur)
{
	int	j;

	cur->height = (int)round(((double)((all->map->len / (cur->distance * \
	all->ray->block / 2 * all->ray->diff_cosinus) * all->map->pp_width))));
	cur->half_height = cur->height / 2;
	j = all->map->half_pp_height;
	count_sprite_column(all, cur);
	all->img_maze->height_mult_by_ll = j * all->img_maze->line_length;
	while (j < cur->half_height + all->map->half_pp_height && j < \
	all->map->pp_height)
	{
		ft_sprite_color_second(all, j, cur);
		all->img_maze->height_mult_by_ll += all->img_maze->line_length;
		j++;
	}
	j = all->map->half_pp_height;
	all->img_maze->height_mult_by_ll = j * all->img_maze->line_length;
	while (j > all->map->half_pp_height - cur->half_height && j >= 0)
	{
		ft_sprite_color_first(all, j, cur);
		j--;
		all->img_maze->height_mult_by_ll -= all->img_maze->line_length;
	}
}

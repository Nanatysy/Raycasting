/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:09:57 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/23 15:23:38 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_get_addr(t_all *all)
{
	all->south->addr = mlx_get_data_addr(all->south->text, \
	&all->south->bits_per_pixel, &all->south->line_length, &all->south->endian);
	all->south->bytes_per_pixel = all->south->bits_per_pixel / 8;
	all->north->addr = mlx_get_data_addr(all->north->text, \
	&all->north->bits_per_pixel, &all->north->line_length, &all->north->endian);
	all->north->bytes_per_pixel = all->north->bits_per_pixel / 8;
	all->west->addr = mlx_get_data_addr(all->west->text, \
	&all->west->bits_per_pixel, &all->west->line_length, &all->west->endian);
	all->west->bytes_per_pixel = all->west->bits_per_pixel / 8;
	all->east->addr = mlx_get_data_addr(all->east->text, \
	&all->east->bits_per_pixel, &all->east->line_length, &all->east->endian);
	all->east->bytes_per_pixel = all->east->bits_per_pixel / 8;
}

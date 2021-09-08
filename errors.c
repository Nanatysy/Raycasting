/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:14:48 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/22 14:05:47 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	mult_inclution(int flag)
{
	int	tmp;

	tmp = flag / 10;
	if (tmp == 1)
		ft_putendl_fd("Resolution was mentioned more than once", 2);
	else if (tmp == 2)
		ft_putendl_fd("Path to the north texture was mentioned \
more than once", 2);
	else if (tmp == 3)
		ft_putendl_fd("Path to the east texture was mentioned \
more than once", 2);
	else if (tmp == 4)
		ft_putendl_fd("Path to the south texture was mentioned \
more than once", 2);
	else if (tmp == 5)
		ft_putendl_fd("Path to the west texture was mentioned \
more than once", 2);
	else if (tmp == 6)
		ft_putendl_fd("Path to the sprite texture was mentioned \
more than once", 2);
	else if (tmp == 7)
		ft_putendl_fd("Floor color was mentioned more than once", 2);
	else if (tmp == 8)
		ft_putendl_fd("Ceilling color was mentioned more than once", 2);
}

void	extra_characters(int flag)
{
	int	tmp;

	tmp = flag / 10;
	if (tmp == 1)
		ft_putendl_fd("Unexpected characters in resolution element line", 2);
	else if (tmp == 2)
		ft_putendl_fd("Unexpected characters in north element line", 2);
	else if (tmp == 3)
		ft_putendl_fd("Unexpected characters in east element line", 2);
	else if (tmp == 4)
		ft_putendl_fd("Unexpected characters in south element line", 2);
	else if (tmp == 5)
		ft_putendl_fd("Unexpected characters in west element line", 2);
	else if (tmp == 6)
		ft_putendl_fd("Unexpected characters in sprite element line", 2);
	else if (tmp == 7)
		ft_putendl_fd("Unexpected characters in floor element line", 2);
	else if (tmp == 8)
		ft_putendl_fd("Unexpected characters in ceilling element line", 2);
}

void	wrong_path(int flag)
{
	int	tmp;

	tmp = flag / 10;
	if (tmp == 2)
		ft_putendl_fd("Wrong path to the north texture", 2);
	else if (tmp == 3)
		ft_putendl_fd("Wrong path to the east texture", 2);
	else if (tmp == 4)
		ft_putendl_fd("Wrong path to the south texture", 2);
	else if (tmp == 5)
		ft_putendl_fd("Wrong path to the west texture", 2);
	else if (tmp == 6)
		ft_putendl_fd("Wrong path to the sprite texture", 2);
}

void	miss_param(int flag)
{
	int	tmp;

	tmp = flag / 10;
	if (tmp == 1)
		ft_putendl_fd("Missing parametr in resolution element line", 2);
	else if (tmp == 2)
		ft_putendl_fd("Missing parametr in north element line", 2);
	else if (tmp == 3)
		ft_putendl_fd("Missing parametr in east element line", 2);
	else if (tmp == 4)
		ft_putendl_fd("Missing parametr in south element line", 2);
	else if (tmp == 5)
		ft_putendl_fd("Missing parametr in west element line", 2);
	else if (tmp == 6)
		ft_putendl_fd("Missing parametr in sprite element line", 2);
	else if (tmp == 7)
		ft_putendl_fd("Missing parametr in floor element line", 2);
	else if (tmp == 8)
		ft_putendl_fd("Missing parametr in ceilling element line", 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 21:19:14 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/23 15:19:36 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	ft_first_error(int flag)
{
	ft_putendl_fd("Error", 2);
	if (flag == 1)
		ft_putendl_fd("Wrong number of arguments", 2);
	else if (flag == 2)
		ft_putendl_fd("Wrong scene description file", 2);
	else if (flag == 3)
		ft_putendl_fd("Failed to open scene description file", 2);
	return (0);
}

int	ft_input_check(int argc, char **argv)
{
	int	fd;
	int	len;

	if (argc != 2 && argc != 3)
		return (ft_first_error(1));
	len = ft_strlen(argv[1]);
	if (!(ft_strnstr(argv[1] + len - 4, ".cub", ft_strlen(argv[1]))))
		return (ft_first_error(2));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_first_error(3));
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7))
			return (ft_first_error(1));
		return (2);
	}
	return (1);
}

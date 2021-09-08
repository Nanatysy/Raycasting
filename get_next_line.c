/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:52:34 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/12 21:11:49 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	get_next_line(char **line, int fd)
{
	int		i;
	char	buf[2];

	if (!(*line = ft_strdup("")))
		return (-1);
	i = read(fd, buf, 1);
	if (i == 0)
		return (i);
	buf[1] = '\0';
	while (buf[0] != '\n' && i != 0)
	{
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		i = read(fd, buf, 1);
		buf[1] = '\0';
	}
	return (i);
}

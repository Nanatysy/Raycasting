/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:16:11 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/21 19:08:22 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_list_fill(t_all *all, char *line, int *end)
{
	t_list	*tmp;

	if (!((ft_strncmp(line, "", 1))))
	{
		*end = 1;
		free(line);
	}
	else if (*end == 1)
		ft_map_er(all, line);
	else
	{
		if (!(tmp = ft_lstnew(line)))
			ft_malloc_er(all, line, 1);
		ft_lstadd_back(&all->map->tmap, tmp);
		free(line);
	}
}

int		ft_check_map_line(char *s1, char *s2)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 1;
	while (s1[i] != '\0' && flag == 1)
	{
		j = 0;
		flag = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				flag = 1;
			j++;
		}
		i++;
	}
	return (flag);
}

void	pre_map_errors(t_all *all, char *line)
{
	if (ft_is_it_map_yet(line, " 10NSWE"))
		ft_trash_error(all, line);
	else
		ft_miss_element(all, line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_list_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:21:26 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/21 20:13:02 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

t_sprite	*spr_new(double x, double y)
{
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

void		spr_push_back(t_sprite *head, double x, double y, t_all *all)
{
	t_sprite	*new;

	if (!(new = spr_new(x, y)))
		my_exit(all);
	while (head->next)
		head = head->next;
	head->next = new;
}

void		sprite_lst(t_all *all, int i, int j)
{
	if (all->map->tsprite == NULL)
	{
		if (!(all->map->tsprite = spr_new((j - 1) * all->ray->block + \
		all->ray->block / 2, i * all->ray->block + all->ray->block / 2)))
			my_exit(all);
		all->map->flag += 1024;
	}
	else
		spr_push_back(all->map->tsprite, (j - 1) * all->ray->block + \
		all->ray->block / 2, i * all->ray->block + all->ray->block / 2, all);
}

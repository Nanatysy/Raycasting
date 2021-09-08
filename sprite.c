/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:57:11 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/23 14:53:37 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		sprite_count(t_sprite *spr)
{
	t_sprite	*tmp;
	int			len;

	tmp = spr;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	sprite_collection(t_all *all)
{
	int			i;
	int			j;

	i = 0;
	all->map->tsprite = NULL;
	while (++i < all->map->map_height)
	{
		j = 1;
		while (all->map->map[i][j] != '\0')
		{
			if (all->map->map[i][j++] == '2')
				sprite_lst(all, i, j);
		}
	}
}

void	sprite_distance_calc(t_all *all)
{
	t_sprite	*tmp;

	tmp = all->map->tsprite;
	while (tmp)
	{
		tmp->distance = sqrt(pow(tmp->x - all->ray->px, 2) + \
		pow(tmp->y - all->ray->py, 2));
		tmp->angle = atan2((tmp->y - all->ray->py), (tmp->x - all->ray->px));
		if (tmp->angle < 0)
			tmp->angle += 2 * M_PI;
		tmp->height = (int)round(((double)((all->map->len / (tmp->distance * \
		all->ray->block / 2) * all->map->pp_width))));
		tmp->l_angle = tmp->angle - all->ray->fov * ((double)(tmp->height) \
		/ 2 / all->map->pp_width);
		if (tmp->l_angle < 0)
			tmp->l_angle += M_PI * 2;
		tmp->r_angle = tmp->angle + all->ray->fov * ((double)(tmp->height) \
		/ 2 / all->map->pp_width);
		if (tmp->r_angle > M_PI * 2)
			tmp->r_angle -= M_PI * 2;
		tmp = tmp->next;
	}
}

void	sprite_swap(t_sprite **cur, t_sprite *next, t_sprite **head, int *flag)
{
	t_sprite	*tmp;
	t_sprite	*head_tmp;
	t_sprite	*cur_tmp;

	*flag = 1;
	cur_tmp = *cur;
	tmp = next;
	cur_tmp->next = next->next;
	tmp->next = cur_tmp;
	if (*head == cur_tmp)
	{
		*head = tmp;
		*cur = *head;
	}
	else
	{
		head_tmp = *head;
		while (head_tmp->next != cur_tmp && head_tmp->next != NULL)
			head_tmp = head_tmp->next;
		head_tmp->next = tmp;
		*cur = head_tmp->next;
	}
}

void	sprite_sort(t_sprite **head)
{
	int			i[2];
	int			len;
	int			flag;
	t_sprite	*current;
	t_sprite	*spr;

	i[0] = 1;
	spr = *head;
	len = sprite_count(spr);
	flag = 1;
	while (i[0] < len && flag == 1)
	{
		i[1] = len;
		current = spr;
		flag = 0;
		while (i[1] > i[0])
		{
			if (current->distance < current->next->distance)
				sprite_swap(&current, current->next, &spr, &flag);
			current = current->next;
			i[1]--;
		}
		i[0]++;
	}
	*head = spr;
}

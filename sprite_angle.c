/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:05:26 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/19 15:51:16 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	angle_check(double ray_ang, t_sprite *cur, double dist)
{
	if (cur->l_angle < cur->r_angle)
	{
		if (ray_ang >= cur->l_angle && ray_ang <= cur->r_angle \
		&& cur->distance < dist)
			return (11);
		return (0);
	}
	else
	{
		if (((ray_ang >= cur->l_angle && ray_ang <= M_PI * 2) || \
		(ray_ang <= cur->r_angle && ray_ang >= 0)) && cur->distance < dist)
			return (21);
		return (0);
	}
}

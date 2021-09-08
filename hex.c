/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:27:52 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/08 19:14:22 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	ft_hex(int r, int g, int b)
{
	int	res;
	int	i;

	i = 5;
	res = 0;
	while (i-- > 0)
	{
		if (i > 3)
		{
			res += (r / (int)(pow(16, i - 4))) * (int)(pow(16, i));
			r %= (int)(pow(16, i - 4));
		}
		else if (i > 1)
		{
			res += (g / (int)(pow(16, i - 2))) * (int)(pow(16, i));
			g %= (int)(pow(16, i - 2));
		}
		else
		{
			res += (b / (int)(pow(16, i))) * (int)(pow(16, i));
			b %= (int)(pow(16, i));
		}
	}
	return (res);
}

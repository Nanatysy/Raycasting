/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:46:10 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/14 16:31:29 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			sign;
	long int	res;

	i = 0;
	sign = 0;
	res = 0;
	j = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = 1;
	while (str[i] >= '0' && str[i] <= '9' && j < 9)
	{
		res = res * 10 + (int)str[i++] - '0';
		if (res != 0)
			j++;
	}
	if (sign == 1)
		return ((int)res * -1);
	return ((int)res);
}

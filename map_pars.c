#include "ft_cub3d.h"

char	**map_list_to_char(t_list **s, t_all *all)
{
	int		len;
	int		tmp;
	t_list	*head;

	head = *s;
	len = ft_lstsize(head);
	all->map->map_width = -1;
	all->map->map_height = len;
	if (!(all->map->map = malloc(sizeof(char *) * len)))
		my_exit(all);
	all->map->count = 0;
	all->map->flag += 512;
	while (all->map->count < all->map->map_height)
	{
		tmp = ft_strlen(head->content);
		if (!(all->map->map[all->map->count] = malloc(sizeof(char) * \
		(tmp + 1))))
			my_exit(all);
		ft_strlcpy(all->map->map[all->map->count++], head->content, tmp + 1);
		all->map->map_width = (tmp > all->map->map_width) ? tmp : \
		all->map->map_width;
		head = head->next;
	}
	return (all->map->map);
}

int		ft_is_it_map_yet(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] == ' ')
		i++;
	while (s2[j] != '\0')
	{
		if (s1[i] == s2[j])
			return (0);
		j++;
	}
	return (1);
}

int		ft_check_o(char **map, int height, int i, int j)
{
	if (i != 0 && i != (height - 1))
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
		{
			if (j == 0 || map[i][j + 1] == '\0')
				return (0);
			if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
				return (0);
			if ((int)ft_strlen(map[i - 1]) <= j || (int)ft_strlen(map[i + 1]) \
			<= j)
				return (0);
			if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
				return (0);
		}
	}
	else
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (0);
	}
	return (1);
}

void	ft_is_it_close(char **map, int height, t_all *all)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!(ft_check_o(map, height, i, j)))
			{
				ft_putendl_fd("Error\nMap isn't closed", 2);
				my_exit(all);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_player(char **map, int height, t_all *all)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < height - 1)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' \
		|| map[i][j] == 'S' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		(count == 0) ? ft_putendl_fd("Error\nMissing spawn position", 2) : \
		ft_putendl_fd("Error\nMultiple spawn position", 2);
		my_exit(all);
	}
}

#include "ft_cub3d.h"

int		ft_mini_atoi(char **str)
{
	int		i;
	int		res;
	char	*tmp;

	i = 0;
	res = 0;
	ft_spaces_skip(str);
	tmp = *str;
	if (!(ft_isdigit(tmp[i])))
		return (-1);
	while (i < 3)
	{
		if (!(ft_isdigit(tmp[i])))
		{
			*str = tmp + i;
			ft_spaces_skip(str);
			return (res);
		}
		res = res * 10 + (int)tmp[i] - '0';
		i++;
	}
	tmp += 3;
	*str = tmp;
	ft_spaces_skip(str);
	return (res);
}

int		ft_spaces_skip(char **s)
{
	char	*tmp;

	tmp = *s;
	while (*tmp != '\0' && *tmp == ' ')
		tmp++;
	*s = tmp;
	if (*tmp != '\0')
		return (1);
	return (0);
}

void	ft_floor(char *str, char *line, t_all *all)
{
	int	r;
	int	g;
	int	b;

	if (all->map->flag & 64)
		print_error(line, all, 72);
	str++;
	ft_spaces_skip(&str);
	if ((r = ft_mini_atoi(&str)) == -1)
		print_error(line, all, 74);
	if (*(str++) != ',')
		print_error(line, all, 71);
	if ((g = ft_mini_atoi(&str)) == -1)
		print_error(line, all, 74);
	if (*(str++) != ',')
		print_error(line, all, 71);
	if ((b = ft_mini_atoi(&str)) == -1)
		print_error(line, all, 74);
	if (ft_spaces_skip(&str))
		print_error(line, all, 71);
	if (r > 255 || g > 255 || b > 255)
		print_error(line, all, 75);
	all->map->floor = ft_hex(r, g, b);
	all->map->flag += 64;
}

void	ft_ceilling(char *str, char *line, t_all *all)
{
	int	r;
	int	g;
	int	b;

	if (all->map->flag & 128)
		print_error(line, all, 82);
	str++;
	ft_spaces_skip(&str);
	if ((r = ft_mini_atoi(&str)) == -1)
		print_error(line, all, 82);
	if (*(str++) != ',')
		print_error(line, all, 81);
	if ((g = ft_mini_atoi(&str)) == -1)
		print_error(line, all, 84);
	if (*(str++) != ',')
		print_error(line, all, 81);
	if ((b = ft_mini_atoi(&str)) == -1)
		print_error(line, all, 84);
	if (ft_spaces_skip(&str))
		print_error(line, all, 81);
	if (r > 255 || g > 255 || b > 255)
		print_error(line, all, 85);
	all->map->ceilling = ft_hex(r, g, b);
	all->map->flag += 128;
}

void	ft_sprite(char *str, char *line, t_all *all)
{
	int		fd;
	int		len;
	char	*tmp;

	if (all->map->flag & 32)
		print_error(line, all, 62);
	str += 2;
	if ((ft_spaces_skip(&str)) == 0)
		print_error(line, all, 64);
	if (!(tmp = ft_strnstr(str, " ", ft_strlen(str))))
		tmp = &str[ft_strlen(str)];
	if (ft_spaces_skip(&tmp))
		print_error(line, all, 61);
	len = ft_strlen(str) - ft_strlen(tmp);
	if (!(all->map->sprite_text = malloc(sizeof(char) * (len + 1))))
		print_error(line, all, 0);
	all->map->flag += 32;
	ft_strlcpy(all->map->sprite_text, str, len + 1);
	if ((fd = open(all->map->sprite_text, O_RDONLY)) == -1)
		print_error(line, all, 63);
	close(fd);
}

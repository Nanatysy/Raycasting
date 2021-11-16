#include "ft_cub3d.h"

void	ft_resolution(char *str, char *line, t_all *all)
{
	int	i;

	i = 0;
	if (all->map->flag & 1)
		print_error(line, all, 12);
	all->map->flag += 1;
	str++;
	if ((ft_spaces_skip(&str)) == 0)
		print_error(line, all, 14);
	all->map->pp_width = ft_atoi(str);
	while (*str != '\0' && ft_isdigit(*str) && i < 4)
		str++;
	if ((ft_spaces_skip(&str)) == 0)
		print_error(line, all, 14);
	all->map->pp_height = ft_atoi(str);
	while (*str != '\0' && ft_isdigit(*str))
		str++;
	if (ft_spaces_skip(&str))
		print_error(line, all, 11);
	if (all->map->pp_height > all->map->max_pp_height || \
	all->map->pp_height < all->map->min_pp_height)
		resolution_height_recalculation(all);
	if (all->map->pp_width > all->map->max_pp_width || \
	all->map->pp_width < all->map->min_pp_width)
		resolution_width_recalculation(all);
}

void	ft_north(char *str, char *line, t_all *all)
{
	int		fd;
	int		len;
	char	*tmp;

	if (all->map->flag & 2)
		print_error(line, all, 22);
	ft_spaces_skip(&str);
	str += 2;
	if ((ft_spaces_skip(&str)) == 0)
		print_error(line, all, 24);
	if (!(tmp = ft_strnstr(str, " ", ft_strlen(str))))
		tmp = &str[ft_strlen(str)];
	if (ft_spaces_skip(&tmp))
		print_error(line, all, 21);
	len = ft_strlen(str) - ft_strlen(tmp);
	if (!(all->map->north_text = malloc(sizeof(char) * (len + 1))))
		print_error(line, all, 0);
	all->map->flag += 2;
	ft_strlcpy(all->map->north_text, str, len + 1);
	if ((fd = open(all->map->north_text, O_RDONLY)) == -1)
		print_error(line, all, 23);
	close(fd);
}

void	ft_east(char *str, char *line, t_all *all)
{
	int		fd;
	int		len;
	char	*tmp;

	if (all->map->flag & 4)
		print_error(line, all, 32);
	str += 2;
	if ((ft_spaces_skip(&str)) == 0)
		print_error(line, all, 34);
	if (!(tmp = ft_strnstr(str, " ", ft_strlen(str))))
		tmp = &str[ft_strlen(str)];
	if (ft_spaces_skip(&tmp))
		print_error(line, all, 31);
	len = ft_strlen(str) - ft_strlen(tmp);
	if (!(all->map->east_text = malloc(sizeof(char) * (len + 1))))
		print_error(line, all, 0);
	all->map->flag += 4;
	ft_strlcpy(all->map->east_text, str, len + 1);
	if ((fd = open(all->map->east_text, O_RDONLY)) == -1)
		print_error(line, all, 33);
	close(fd);
}

void	ft_south(char *str, char *line, t_all *all)
{
	int		fd;
	int		len;
	char	*tmp;

	if (all->map->flag & 8)
		print_error(line, all, 42);
	str += 2;
	if ((ft_spaces_skip(&str)) == 0)
		print_error(line, all, 44);
	if (!(tmp = ft_strnstr(str, " ", ft_strlen(str))))
		tmp = &str[ft_strlen(str)];
	if (ft_spaces_skip(&tmp))
		print_error(line, all, 41);
	len = ft_strlen(str) - ft_strlen(tmp);
	if (!(all->map->south_text = malloc(sizeof(char) * (len + 1))))
		print_error(line, all, 0);
	all->map->flag += 8;
	ft_strlcpy(all->map->south_text, str, len + 1);
	if ((fd = open(all->map->south_text, O_RDONLY)) == -1)
		print_error(line, all, 43);
	close(fd);
}

void	ft_west(char *str, char *line, t_all *all)
{
	int		fd;
	int		len;
	char	*tmp;

	if (all->map->flag & 16)
		print_error(line, all, 52);
	str += 2;
	if ((ft_spaces_skip(&str)) == 0)
		print_error(line, all, 54);
	if (!(tmp = ft_strnstr(str, " ", ft_strlen(str))))
		tmp = &str[ft_strlen(str)];
	if (ft_spaces_skip(&tmp))
		print_error(line, all, 51);
	len = ft_strlen(str) - ft_strlen(tmp);
	if (!(all->map->west_text = malloc(sizeof(char) * (len + 1))))
		print_error(line, all, 0);
	all->map->flag += 16;
	ft_strlcpy(all->map->west_text, str, len + 1);
	if ((fd = open(all->map->west_text, O_RDONLY)) == -1)
		print_error(line, all, 53);
	close(fd);
}

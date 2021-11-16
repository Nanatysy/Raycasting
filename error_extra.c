#include "ft_cub3d.h"

void	ft_map_er(t_all *all, char *line)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("\\n in the mid of a map or it isn't the last \
element in the file", 2);
	free(line);
	my_exit(all);
}

void	ft_malloc_er(t_all *all, char *line, int flag)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Memory allocation error", 2);
	if (flag)
		free(line);
	my_exit(all);
}

void	ft_miss_element(t_all *all, char *line)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Missing elements", 2);
	free(line);
	my_exit(all);
}

void	ft_trash_error(t_all *all, char *line)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Some kind of trash in the file", 2);
	free(line);
	my_exit(all);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:49:25 by dwillett          #+#    #+#             */
/*   Updated: 2020/12/22 14:06:15 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	print_error(char *line, t_all *all, int error_flag)
{
	ft_putendl_fd("Error", 2);
	free(line);
	if (error_flag % 10 == 1)
		extra_characters(error_flag);
	else if (error_flag % 10 == 2)
		mult_inclution(error_flag);
	else if (error_flag % 10 == 3)
		wrong_path(error_flag);
	else if (error_flag % 10 == 4)
		miss_param(error_flag);
	else if (error_flag % 10 == 5)
	{
		if (error_flag / 10 == 7)
			ft_putendl_fd("Invalid value for floor color", 2);
		else
			ft_putendl_fd("Invalid value for ceilling color", 2);
	}
	else
		ft_putendl_fd("Memory allocation error", 2);
	my_exit(all);
}

void	ft_check_element(char *line, t_all *all)
{
	char	*tmp;

	if ((ft_strnstr(line, "R", ft_strlen(line))))
		ft_resolution((tmp = line), line, all);
	else if ((ft_strnstr(line, "NO", ft_strlen(line))))
		ft_north((tmp = line), line, all);
	else if ((ft_strnstr(line, "EA", ft_strlen(line))))
		ft_east((tmp = line), line, all);
	else if ((ft_strnstr(line, "SO", ft_strlen(line))))
		ft_south((tmp = line), line, all);
	else if ((ft_strnstr(line, "WE", ft_strlen(line))))
		ft_west((tmp = line), line, all);
	else if ((ft_strnstr(line, "S ", ft_strlen(line))))
		ft_sprite((tmp = line), line, all);
	else if ((ft_strnstr(line, "F", ft_strlen(line))))
		ft_floor((tmp = line), line, all);
	else if ((ft_strnstr(line, "C", ft_strlen(line))))
		ft_ceilling((tmp = line), line, all);
	else
	{
		ft_putendl_fd("Error\nSome kind of trash in the file", 2);
		free(line);
		my_exit(all);
	}
}

void	ft_check_char(t_list **tmap, t_all *all)
{
	t_list	*tmp;

	tmp = *tmap;
	while (tmp)
	{
		if (!(ft_check_map_line(tmp->content, " 102NSWE")))
		{
			ft_putendl_fd("Error\nInvalid characters in map", 2);
			my_exit(all);
		}
		tmp = tmp->next;
	}
}

void	get_map_info(int fd, char *line, t_all *all)
{
	int		flag;
	int		end;

	if (!(all->map->tmap = ft_lstnew(line)))
		ft_malloc_er(all, line, 1);
	all->map->flag += 256;
	free(line);
	end = 0;
	while ((flag = get_next_line(&line, fd)))
		ft_list_fill(all, line, &end);
	if (flag == 0)
	{
		if ((ft_strncmp(line, "", 1)))
			(end != 1) ? ft_lstadd_back(&all->map->tmap, \
			ft_lstnew(line)) : ft_map_er(all, line);
		free(line);
	}
	else
		ft_malloc_er(all, line, 0);
	ft_check_char(&all->map->tmap, all);
	ft_is_it_close(map_list_to_char(&all->map->tmap, all), \
	all->map->map_height, all);
	ft_check_player(all->map->map, all->map->map_height, all);
	sprite_collection(all);
}

void	get_info(char *str, t_all *all)
{
	int		fd;
	int		flag;
	char	*line;

	if (!(fd = open(str, O_RDONLY)))
		my_exit(all);
	while ((flag = get_next_line(&line, fd)))
	{
		if ((ft_strncmp(line, "", 1)))
		{
			if ((ft_is_it_map_yet(line, "RNSEWFC")) == 1)
				break ;
			ft_check_element(line, all);
		}
		free(line);
	}
	if (flag == -1)
		ft_malloc_er(all, line, 0);
	if (all->map->flag != 255)
		pre_map_errors(all, line);
	if (ft_is_it_map_yet(line, " 10NSWE"))
		ft_trash_error(all, line);
	get_map_info(fd, line, all);
	close(fd);
}

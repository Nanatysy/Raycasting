#include "ft_cub3d.h"

void	ft_byte_shift(int num, unsigned char *str)
{
	str[0] = (unsigned char)(num);
	str[1] = (unsigned char)(num >> 8);
	str[2] = (unsigned char)(num >> 16);
	str[3] = (unsigned char)(num >> 24);
}

void	ft_put_bmpheader(int fd, t_all *all)
{
	int				i;
	unsigned char	str[54];

	i = 0;
	while (i < 54)
		str[i++] = 0;
	str[0] = 'B';
	str[1] = 'M';
	ft_byte_shift(all->map->pp_height * all->map->pp_width * 4 + 54, str + 2);
	str[10] = 54;
	str[14] = 40;
	ft_byte_shift(all->map->pp_width, str + 18);
	ft_byte_shift(all->map->pp_height, str + 22);
	str[26] = 1;
	str[28] = 32;
	write(fd, str, 54);
}

void	ft_put_color_bmp(int color, int fd)
{
	unsigned char	tmp[4];

	ft_byte_shift(color, tmp);
	write(fd, tmp, 4);
}

void	save(t_all *all)
{
	int				fd;
	int				i;
	int				j;
	int				color;

	if ((fd = open("deepthought.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, \
	0666)) == -1)
	{
		ft_putendl_fd("Error\nFailed to create deepthought file", 2);
		my_exit(all);
	}
	ft_put_bmpheader(fd, all);
	j = all->map->pp_height;
	while (j-- > 0)
	{
		i = -1;
		while (++i < all->map->pp_width)
		{
			color = *(unsigned int*)(all->img_maze->addr + (j * all->img_maze->\
			line_length + i * (all->img_maze->bits_per_pixel / 8)));
			ft_put_color_bmp(color, fd);
		}
	}
	close(fd);
}

#include "cub3d.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!data->img || !data->img->img || !data->img->img_addr)
		return ;
	dst = data->img->img_addr + (y * data->img->line_length + x
			* (data->img->bpp >> 3));
	*(unsigned int *)dst = color;
}

int	ft_mlx_pixel_get(t_data *data, int x, int y, int texture_num)
{
	char	*dst;

	dst = data->textures[texture_num] + (y * data->text_line_len[texture_num]
			+ x * (data->text_bpp[texture_num] >> 3));
	return (*(unsigned int *)dst);
}

void	display_fc(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				ft_mlx_pixel_put(data, x, y, data->d_map->c_rgb);
			else
				ft_mlx_pixel_put(data, x, y, data->d_map->f_rgb);
		}
	}
}

void	minimap_drawing(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	i;
	int	j;

	y = 9;
	while (++y < data->d_map->height + 10)
	{
		x = 9;
		while (++x < data->d_map->width + 10)
		{
			if (data->d_map->map[y][x] == ' ')
				continue ;
			if (data->d_map->map[y][x] == '1')
				color = MINMAP_WALL;
			else if (data->d_map->map[y][x] == 'P')
				color = MINMAP_PLAYER;
			else
				color = MINMAP_FLOOR;
			i = -1;
			while (++i < 3)
			{
				j = -1;
				while (++j < 3)
					ft_mlx_pixel_put(data, (x - 10) + i,
						(y - 10) + j, color);
			}
		}
	}
}

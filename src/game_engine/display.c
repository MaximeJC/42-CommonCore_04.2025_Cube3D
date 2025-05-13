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

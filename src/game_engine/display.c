#include "cub3d.h"

static void	display_fc(t_data *data);
static void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

void	display_once(t_data *data)
{
	display_fc(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
}

static void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!data->img || !data->img->img || !data->img->img_addr)
		return ;
	dst = data->img->img_addr + (y * data->img->line_length + x
			* (data->img->bpp >> 3));
	*(unsigned int *)dst = color;
}

static void	display_fc(t_data *data)
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

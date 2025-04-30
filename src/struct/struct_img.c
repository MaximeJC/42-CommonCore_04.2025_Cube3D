#include "cub3d.h"

int	init_img(t_data *data)
{
	data->img = ft_calloc(1, sizeof(t_img));
	if (!data->img)
		return (1);
	data->img->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img->img)
		return (1);
	data->img->img_addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
		&data->img->line_length, &data->img->endian);
	if (!data->img->img_addr)
		return (1);
	return (0);
}

void	clear_img(t_data *data)
{
	if (!data->img)
		return ;
	if (data->img->img)
		mlx_destroy_image(data->mlx_ptr, data->img->img);
	free(data->img);
}

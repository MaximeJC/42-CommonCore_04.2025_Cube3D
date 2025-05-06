#include "cub3d.h"

void	mlx_win_init(t_data *data)
{
	int	temp;

	temp = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (error_handler(ERR_MLX_INIT, data, 1));
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
			"Cub3D Museum");
	if (!data->mlx_win)
		return (error_handler(ERR_WIN_INIT, data, 1));
	data->d_map->no_text_mlx = MLX_IMG_INIT(data->mlx_ptr,
			data->d_map->no_texture, &temp, &temp);
	data->d_map->so_text_mlx = MLX_IMG_INIT(data->mlx_ptr,
			data->d_map->so_texture, &temp, &temp);
	data->d_map->ea_text_mlx = MLX_IMG_INIT(data->mlx_ptr,
			data->d_map->ea_texture, &temp, &temp);
	data->d_map->we_text_mlx = MLX_IMG_INIT(data->mlx_ptr,
			data->d_map->we_texture, &temp, &temp);
	if (!data->d_map->no_text_mlx || !data->d_map->so_text_mlx
		|| !data->d_map->ea_text_mlx || !data->d_map->we_text_mlx)
		return (error_handler(ERR_IMG_INIT, data, 1));
	if (init_img(data))
		return (error_handler(ERR_IMG_SCREEN, data, 1));
}

int	close_mlx(t_data *data)
{
	clear_data(data);
	exit(0);
}

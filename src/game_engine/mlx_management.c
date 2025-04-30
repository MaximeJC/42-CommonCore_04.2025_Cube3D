#include "cub3d.h"

void	mlx_win_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (error_handler(ERR_MLX_INIT, data, 1));
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
		"Cub3D Museum");
	if (!data->mlx_win)
		return (error_handler(ERR_WIN_INIT, data, 1));
	data->d_map->no_text_mlx = MLX_IMG_INIT(data->mlx_ptr,
		data->d_map->no_texture, IMG_SIZE, IMG_SIZE);
	data->d_map->so_text_mlx = MLX_IMG_INIT(data->mlx_ptr,
		data->d_map->so_texture, IMG_SIZE, IMG_SIZE);
	data->d_map->ea_text_mlx = MLX_IMG_INIT(data->mlx_ptr,
		data->d_map->ea_texture, IMG_SIZE, IMG_SIZE);
	data->d_map->we_text_mlx = MLX_IMG_INIT(data->mlx_ptr,
		data->d_map->we_texture, IMG_SIZE, IMG_SIZE);
	if (!data->d_map->no_text_mlx || !data->d_map->so_text_mlx
		|| !data->d_map->ea_text_mlx || !data->d_map->we_text_mlx)
		return (error_handler(ERR_IMG_INIT, data, 1));
}

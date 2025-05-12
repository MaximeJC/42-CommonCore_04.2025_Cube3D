#include "cub3d.h"

static void	mlx_win_init_bis(t_data *data);

void	mlx_win_init(t_data *data)
{
	int	temp;

	temp = 0;
	if (!ft_isvalid_str(data->d_map->no_texture)
		|| !ft_isvalid_str(data->d_map->so_texture)
		|| !ft_isvalid_str(data->d_map->ea_texture)
		|| !ft_isvalid_str(data->d_map->we_texture))
		return (error_handler(ERR_TEXTURE, data, 1));
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (error_handler(ERR_MLX_INIT, data, 1));
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
	return (mlx_win_init_bis(data));
}

static void	mlx_win_init_bis(t_data *data)
{
	data->textures[NO_TEXTURE] = mlx_get_data_addr(data->d_map->no_text_mlx,
			&data->text_bpp[0], &data->text_line_len[0], &data->text_endian[0]);
	data->textures[SO_TEXTURE] = mlx_get_data_addr(data->d_map->so_text_mlx,
			&data->text_bpp[1], &data->text_line_len[1], &data->text_endian[1]);
	data->textures[EA_TEXTURE] = mlx_get_data_addr(data->d_map->ea_text_mlx,
			&data->text_bpp[2], &data->text_line_len[2], &data->text_endian[2]);
	data->textures[WE_TEXTURE] = mlx_get_data_addr(data->d_map->we_text_mlx,
			&data->text_bpp[3], &data->text_line_len[3], &data->text_endian[3]);
	if (!data->textures[0] || !data->textures[1]
		|| !data->textures[2] || !data->textures[3])
		return (error_handler(ERR_IMG_INIT, data, 1));
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
			"Cub3D Museum");
	if (!data->mlx_win)
		return (error_handler(ERR_WIN_INIT, data, 1));
	if (init_img(data))
		return (error_handler(ERR_IMG_SCREEN, data, 1));
}

int	close_mlx(t_data *data)
{
	clear_data(data);
	exit(0);
}

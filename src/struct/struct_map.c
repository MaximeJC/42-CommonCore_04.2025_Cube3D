#include "cub3d.h"

int	init_map(t_data *data)
{
	data->d_map = malloc(sizeof(t_map));
	if (data->d_map == NULL)
		return (error_handler(ERR_MALLOC, NULL, 0), 1);
	data->d_map->no_texture = NULL;
	data->d_map->so_texture = NULL;
	data->d_map->ea_texture = NULL;
	data->d_map->we_texture = NULL;
	data->d_map->no_text_mlx = NULL;
	data->d_map->so_text_mlx = NULL;
	data->d_map->ea_text_mlx = NULL;
	data->d_map->we_text_mlx = NULL;
	data->d_map->map = NULL;
	data->d_map->width = 0;
	data->d_map->height = 0;
	data->d_map->c_rgb = -1;
	data->d_map->f_rgb = -1;
	return (0);
}

void	clear_map(t_data *data)
{
	if (!data->d_map)
		return ;
	if (data->d_map->no_texture)
		free(data->d_map->no_texture);
	if (data->d_map->so_texture)
		free(data->d_map->so_texture);
	if (data->d_map->ea_texture)
		free(data->d_map->ea_texture);
	if (data->d_map->we_texture)
		free(data->d_map->we_texture);
	if (data->d_map->no_text_mlx)
		mlx_destroy_image(data->mlx_ptr, data->d_map->no_text_mlx);
	if (data->d_map->so_text_mlx)
		mlx_destroy_image(data->mlx_ptr, data->d_map->so_text_mlx);
	if (data->d_map->ea_text_mlx)
		mlx_destroy_image(data->mlx_ptr, data->d_map->ea_text_mlx);
	if (data->d_map->we_text_mlx)
		mlx_destroy_image(data->mlx_ptr, data->d_map->we_text_mlx);
	if (data->d_map->map)
		ft_strtab_free(data->d_map->map);
	free(data->d_map);
}

#include "cub3d.h"

int	init_data(t_data *data, char *file)
{
	data->filename = file;
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	if (init_map(data))
		return (1);
	return (init_player(data));
}

void	clear_data(t_data *data)
{
	if (!data)
		return ;
	if (data->d_map)
		clear_map(data);
	if (data->player)
		clear_player(data);
	if (data->img)
		clear_img(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

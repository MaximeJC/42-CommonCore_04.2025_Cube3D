#include "cub3d.h"

int	init_player(t_data *data)
{
	data->player = ft_calloc(1, sizeof(t_player));
	if (data->player == NULL)
		return (error_handler(ERR_MALLOC, NULL, 0), 1);
	data->player->pos_x = 0;
	data->player->pos_y = 0;
	data->player->dir_x = 0;
	data->player->dir_y = 0;
	data->player->plan_x = 0;
	data->player->plan_y = 0;
	return (0);
}

void	clear_player(t_data *data)
{
	if (data->player)
		free(data->player);
}

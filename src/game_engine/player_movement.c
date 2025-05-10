#include "cub3d.h"

void	player_move_up_down(t_data *data, double speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->player->pos_x + data->player->dir_x * speed;
	new_pos_y = data->player->pos_y + data->player->dir_y * speed;
	if (data->d_map->map[(int)data->player->pos_y][(int)new_pos_x] != '1')
		data->player->pos_x = new_pos_x;
	if (data->d_map->map[(int)new_pos_y][(int)data->player->pos_x] != '1')
		data->player->pos_y = new_pos_y;
	game_engine(data);
}

void	player_move_left_right(t_data *data, double speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->player->pos_x + data->player->plan_x * speed;
	new_pos_y = data->player->pos_y + data->player->plan_y * speed;
	if (data->d_map->map[(int)data->player->pos_y][(int)new_pos_x] != '1')
		data->player->pos_x = new_pos_x;
	if (data->d_map->map[(int)new_pos_y][(int)data->player->pos_x] != '1')
		data->player->pos_y = new_pos_y;
	game_engine(data);
}

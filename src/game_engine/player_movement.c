/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:37:57 by nicolmar          #+#    #+#             */
/*   Updated: 2025/05/13 11:37:58 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move_up_down(t_data *data, double speed)
{
	double	new_pos_x;
	double	new_pos_y;
	int		old_pos_x;
	int		old_pos_y;

	old_pos_x = (int)data->player->pos_x;
	old_pos_y = (int)data->player->pos_y;
	new_pos_x = data->player->pos_x + data->player->dir_x * speed;
	new_pos_y = data->player->pos_y + data->player->dir_y * speed;
	if (data->d_map->map[(int)data->player->pos_y][(int)new_pos_x] != '1')
		data->player->pos_x = new_pos_x;
	if (data->d_map->map[(int)new_pos_y][(int)data->player->pos_x] != '1')
		data->player->pos_y = new_pos_y;
	if (old_pos_x != (int)data->player->pos_x
		|| old_pos_y != (int)data->player->pos_y)
		data->d_map->map[old_pos_y][old_pos_x] = '0';
	data->d_map->map[(int)data->player->pos_y][(int)data->player->pos_x] = 'P';
	game_engine(data);
}

void	player_move_left_right(t_data *data, double speed)
{
	double	new_pos_x;
	double	new_pos_y;
	int		old_pos_x;
	int		old_pos_y;

	old_pos_x = (int)data->player->pos_x;
	old_pos_y = (int)data->player->pos_y;
	new_pos_x = data->player->pos_x + data->player->plan_x * speed;
	new_pos_y = data->player->pos_y + data->player->plan_y * speed;
	if (data->d_map->map[(int)data->player->pos_y][(int)new_pos_x] != '1')
		data->player->pos_x = new_pos_x;
	if (data->d_map->map[(int)new_pos_y][(int)data->player->pos_x] != '1')
		data->player->pos_y = new_pos_y;
	if (old_pos_x != (int)data->player->pos_x
		|| old_pos_y != (int)data->player->pos_y)
		data->d_map->map[old_pos_y][old_pos_x] = '0';
	data->d_map->map[(int)data->player->pos_y][(int)data->player->pos_x] = 'P';
	game_engine(data);
}

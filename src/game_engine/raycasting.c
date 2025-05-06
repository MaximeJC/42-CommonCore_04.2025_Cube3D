#include "cub3d.h"

void	raycast_once(t_data *data)
{
	data->ray->camera_x = 2 * data->ray->x / (double)WIDTH - 1;
	data->ray->ray_dir_x = data->player->dir_x + data->player->plan_x * data->ray->camera_x;
	data->ray->ray_dir_y = data->player->dir_y + data->player->plan_y * data->ray->camera_x;
}

//! Init map_x / map_y
//! Init delta_dist_x / delta_dist_y

void	dad_algorythm(t_data *data)
{
	while (data->ray->hit == 0)
	{
		if (data->ray->side_dist_x < data->ray->side_dist_y)
		{
			data->ray->side_dist_x += data->ray->delta_dist_x;
			data->ray->map_x += data->ray->step_x;
			data->ray->side = 0;	//Mur vertical
		}
		else
		{
			data->ray->side_dist_y += data->ray->delta_dist_y;
			data->ray->map_y += data->ray->step_y;
			data->ray->side = 1;	//Mur horizontal
		}
		if (data->d_map->map[data->ray->map_y][data->ray->map_x] > 0)
			data->ray->hit = 1;
	}
}

#include "cub3d.h"

void	ray_init(t_data *data);
void	ray_init_bis(t_data *data);
void	dad_algorythm(t_data *data);
void	draw_vertical_line(t_data *data);

void	game_engine(t_data *data)
{
	data->ray->x = -1;
	display_fc(data);
	while (++data->ray->x < WIDTH)
	{
		ray_init(data);
		dad_algorythm(data);
		data->ray->line_height = (int)(HEIGHT / data->ray->perp_wall_dist
				* 1.4);
		data->ray->draw_start_pix = -data->ray->line_height / 2 + HEIGHT / 2;
		if (data->ray->draw_start_pix < 0)
			data->ray->draw_start_pix = 0;
		data->ray->draw_end_pix = data->ray->line_height / 2 + HEIGHT / 2;
		if (data->ray->draw_end_pix >= HEIGHT)
			data->ray->draw_end_pix = HEIGHT - 1;
		draw_vertical_line(data);
	}
	MLX_IMG_WIN(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
}

void	ray_init(t_data *data)
{
	data->ray->camera_x = 2 * (data->ray->x + 0.000001) / (double)WIDTH - 1;
	data->ray->ray_dir_x = data->player->dir_x + data->player->plan_x
		* data->ray->camera_x;
	data->ray->ray_dir_y = data->player->dir_y + data->player->plan_y
		* data->ray->camera_x;
	if (data->ray->ray_dir_x == 0)
		data->ray->delta_dist_x = pow(1, 30);
	else
		data->ray->delta_dist_x = fabs(1 / data->ray->ray_dir_x);
	if (data->ray->ray_dir_y == 0)
		data->ray->delta_dist_y = pow(1, 30);
	else
		data->ray->delta_dist_y = fabs(1 / data->ray->ray_dir_y);
	data->ray->map_x = trunc(data->player->pos_x);
	data->ray->map_y = trunc(data->player->pos_y);
	data->ray->hit = 0;
	ray_init_bis(data);
}

void	ray_init_bis(t_data *data)
{
	if (data->ray->ray_dir_x < 0)
	{
		data->ray->step_x = -1;
		data->ray->side_dist_x = (data->player->pos_x - data->ray->map_x)
			* data->ray->delta_dist_x;
	}
	else
	{
		data->ray->step_x = 1;
		data->ray->side_dist_x = (data->ray->map_x + 1.0 - data->player->pos_x)
			* data->ray->delta_dist_x;
	}
	if (data->ray->ray_dir_y < 0)
	{
		data->ray->step_y = -1;
		data->ray->side_dist_y = (data->player->pos_y - data->ray->map_y)
			* data->ray->delta_dist_y;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->side_dist_y = (data->ray->map_y + 1.0 - data->player->pos_y)
			* data->ray->delta_dist_y;
	}
}

void	dad_algorythm(t_data *data)
{
	while (data->ray->hit == 0)
	{
		if (data->ray->side_dist_x < data->ray->side_dist_y)
		{
			data->ray->side_dist_x += data->ray->delta_dist_x;
			data->ray->map_x += data->ray->step_x;
			data->ray->side = 0; //Mur vertical
		}
		else
		{
			data->ray->side_dist_y += data->ray->delta_dist_y;
			data->ray->map_y += data->ray->step_y;
			data->ray->side = 1; //Mur horizontal
		}
		if (data->d_map->map[data->ray->map_y][data->ray->map_x] == '1')
			data->ray->hit = 1;
	}
	if (data->ray->side == 0)
		data->ray->perp_wall_dist = data->ray->side_dist_x
			- data->ray->delta_dist_x;
	else
		data->ray->perp_wall_dist = data->ray->side_dist_y
			- data->ray->delta_dist_y;
}

#define NORTH_COLOR 16711680	//RED
#define SOUTH_COLOR 65280		//GREEN
#define EAST_COLOR 255			//BLUE
#define WEST_COLOR 16776960		//YELLOW

void	draw_vertical_line(t_data *data)
{
	int	color;
	int	i;

	i = data->ray->draw_start_pix;
	if (data->ray->side == 0)
	{
		if (data->ray->ray_dir_x > 0)
			color = EAST_COLOR;
		else
			color = WEST_COLOR;
	}
	else
	{
		if (data->ray->ray_dir_y > 0)
			color = SOUTH_COLOR;
		else
			color = NORTH_COLOR;
	}
	if (data->ray->side == 0)
		color *= 0.8;
	while (i <= data->ray->draw_end_pix)
	{
		ft_mlx_pixel_put(data, data->ray->x, i, color);
		i++;
	}
}

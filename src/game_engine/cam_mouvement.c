#include "cub3d.h"

void	cam_mouvemenmt(t_data *data, double old_pos_x, double old_pos_y,
	double degres)
{
	double	angle;
	double	cos_a;
	double	sin_a;
	double	old_plan_x;
	double	old_plan_y;

	angle = degres * M_PI / 180;
	cos_a = cos(angle);
	sin_a = sin(angle);
	old_plan_x = data->player->plan_x;
	old_plan_y = data->player->plan_y;
	data->player->dir_x = old_pos_x * cos_a - old_pos_y * sin_a;
	data->player->dir_y = old_pos_x * sin_a + old_pos_y * cos_a;
	data->player->plan_x = old_plan_x * cos_a - old_plan_y * sin_a;
	data->player->plan_y = old_plan_x * sin_a + old_plan_y * cos_a;
	game_engine(data);
	// printf("old dir_x: %f old dir_y: %f\n", old_pos_x, old_pos_y);
	// printf("act dir_x: %f act dir_y: %f\n",
	// 	data->player->dir_x, data->player->dir_y);
	// fflush(stdout);
}

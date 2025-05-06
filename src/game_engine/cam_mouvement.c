#include "cub3d.h"

void	cam_mouvemenmt(t_data *data, double x, double y, double degres)
{
	double	angle;
	double	cos_a;
	double	sin_a;

	angle = degres * M_PI / 180;
	cos_a = cos(angle);
	sin_a = sin(angle);
	data->player->dir_x = x * cos_a - y * sin_a;
	data->player->dir_y = x * sin_a + y * cos_a;
	printf("old dir_x: %f old dir_y: %f\n", x, y);
	printf("act dir_x: %f act dir_y: %f\n",
		data->player->dir_x, data->player->dir_y);
	fflush(stdout);
}

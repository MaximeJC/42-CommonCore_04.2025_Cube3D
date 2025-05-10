#include "cub3d.h"

int	key_press(int keycode, t_data *data)
{
	double speed;

	speed = 0.1;
	ft_printf("keycode: %d\n", keycode);
	if (keycode == KEY_CTRL)
		speed = 0.2;
	if (keycode == KEY_ESC)
		close_mlx(data);
	if (keycode == KEY_LEFT)
		cam_mouvemenmt(data, data->player->dir_x,
			data->player->dir_y, -CAM_ROT_SPEED);
	if (keycode == KEY_RIGHT)
		cam_mouvemenmt(data, data->player->dir_x,
			data->player->dir_y, CAM_ROT_SPEED);
	if (keycode == KEY_W)
	 	player_move_up_down(data, speed);
	if (keycode == KEY_S)
		player_move_up_down(data, -speed);
	if (keycode == KEY_A)
		player_move_left_right(data, -speed);
	if (keycode == KEY_D)
		player_move_left_right(data, speed);
	
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	double	delta_x;
	double	sensibility;
	double	angle;

	if (x == WIDTH / 2 && y == HEIGHT / 2)
		return (0);
	delta_x = 0;
	sensibility = 0.01;
	angle = 0;
	(void)y;
	delta_x = x - WIDTH / 2;
	angle = delta_x * sensibility;
	cam_mouvemenmt(data, data->player->dir_x, data->player->dir_y, angle);
	mlx_mouse_move(data->mlx_ptr, data->mlx_win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

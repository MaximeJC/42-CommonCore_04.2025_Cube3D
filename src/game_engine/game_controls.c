#include "cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode < 0 || keycode >= MAX_KEYS)
		return (0);
	data->keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode < 0 || keycode >= MAX_KEYS)
		return (0);
	data->keys[keycode] = 0;
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

int	handle_keys(t_data *data)
{
	double	speed;

	speed = 0.1;
	if (data->keys[KEY_CTRL])
		speed = 0.2;
	if (data->keys[KEY_ESC])
		close_mlx(data);
	if (data->keys[KEY_LEFT])
		cam_mouvemenmt(data, data->player->dir_x,
			data->player->dir_y, -CAM_ROT_SPEED);
	if (data->keys[KEY_RIGHT])
		cam_mouvemenmt(data, data->player->dir_x,
			data->player->dir_y, CAM_ROT_SPEED);
	if (data->keys[KEY_W])
		player_move_up_down(data, speed);
	if (data->keys[KEY_S])
		player_move_up_down(data, -speed);
	if (data->keys[KEY_A])
		player_move_left_right(data, -speed);
	if (data->keys[KEY_D])
		player_move_left_right(data, speed);
	return (0);
}

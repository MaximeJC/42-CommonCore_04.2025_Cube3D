/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:42 by nicolmar          #+#    #+#             */
/*   Updated: 2025/05/13 11:38:43 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arg(int argc)
{
	if (argc > 2)
		return (ft_putendl_fd(ERR_TM_AR, 2), 1);
	else if (argc < 2)
		return (ft_putendl_fd(ERR_NE_AR, 2), 1);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	if (check_arg(argc) || check_mapfile((char *)argv[1]))
		return (1);
	if (init_data(&data, (char *)argv[1]))
		return (clear_data(&data), 1);
	if (get_data_map(&data, 0) != 0)
		return (clear_data(&data), 1);
	if (check_wall_and_ground(&data) != 0)
		return (clear_data(&data), 1);
	init_raycast(&data);
	mlx_win_init(&data);
	mlx_mouse_hide(data.mlx_ptr, data.mlx_win);
	mlx_hook(data.mlx_win, 6, 1L << 6, mouse_move, &data);
	mlx_hook(data.mlx_win, 17, 0, close_mlx, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx_ptr, handle_keys, &data);
	game_engine(&data);
	mlx_loop(data.mlx_ptr);
	return (clear_data(&data), 0);
}

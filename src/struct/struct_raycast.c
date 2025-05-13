/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:32 by nicolmar          #+#    #+#             */
/*   Updated: 2025/05/13 11:38:33 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_raycast(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_raycast));
	if (!data->ray)
		return (error_handler(ERR_MALLOC, data, 1), 1);
	data->ray->ray_dir_x = 0;
	data->ray->ray_dir_y = 0;
	data->ray->camera_x = 0;
	data->ray->map_x = 0;
	data->ray->map_y = 0;
	data->ray->side_dist_x = 0;
	data->ray->side_dist_y = 0;
	data->ray->delta_dist_x = 0;
	data->ray->delta_dist_y = 0;
	data->ray->step_x = 0;
	data->ray->step_y = 0;
	data->ray->hit = 0;
	data->ray->side = 0;
	data->ray->perp_wall_dist = 0;
	data->ray->line_height = 0;
	data->ray->draw_start_pix = 0;
	data->ray->draw_end_pix = 0;
	data->ray->x = 0;
	return (0);
}

void	clear_raycast(t_data *data)
{
	if (data->ray)
		free(data->ray);
}

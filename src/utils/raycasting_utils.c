/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:39 by nicolmar          #+#    #+#             */
/*   Updated: 2025/05/13 11:38:40 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_texture_bis(t_data *data, int texture_num, double wall_x);

int	ft_color_shadow(int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (r * 85) >> 7;
	g = (g * 85) >> 7;
	b = (b * 85) >> 7;
	return ((r << 16) | (g << 8) | b);
}

void	draw_texture(t_data *data)
{
	int		texture_num;
	double	wall_x;

	if (data->ray->side == 0)
	{
		wall_x = data->player->pos_y + data->ray->perp_wall_dist
			* data->ray->ray_dir_y;
		if (data->ray->ray_dir_x > 0)
			texture_num = EA_TEXTURE;
		else
			texture_num = WE_TEXTURE;
	}
	else
	{
		wall_x = data->player->pos_x + data->ray->perp_wall_dist
			* data->ray->ray_dir_x;
		if (data->ray->ray_dir_y > 0)
			texture_num = SO_TEXTURE;
		else
			texture_num = NO_TEXTURE;
	}
	draw_texture_bis(data, texture_num, wall_x);
}

static void	draw_texture_bis(t_data *data, int texture_num, double wall_x)
{
	int		text_x;
	double	step;
	double	text_pos;
	int		y;

	wall_x -= floor(wall_x);
	text_x = (int)(wall_x * (double)IMG_SIZE);
	if (texture_num == NO_TEXTURE || texture_num == EA_TEXTURE)
		text_x = IMG_SIZE - text_x - 1;
	step = 1.0 * IMG_SIZE / data->ray->line_height;
	text_pos = (data->ray->draw_start_pix - HEIGHT / 2
			+ data->ray->line_height / 2) * step;
	y = data->ray->draw_start_pix;
	while (y < data->ray->draw_end_pix)
	{
		text_pos += step;
		if (data->ray->side == 0)
			ft_mlx_pixel_put(data, data->ray->x, y, ft_mlx_pixel_get(data,
					text_x, (int)text_pos & (IMG_SIZE - 1), texture_num));
		else
			ft_mlx_pixel_put(data, data->ray->x, y, ft_color_shadow(
					ft_mlx_pixel_get(data, text_x, (int)text_pos
						& (IMG_SIZE - 1), texture_num)));
		y++;
	}
}

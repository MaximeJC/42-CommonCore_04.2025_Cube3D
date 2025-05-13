/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:15 by nicolmar          #+#    #+#             */
/*   Updated: 2025/05/13 15:26:00 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_empty_line(char *line, int err)
{
	static int c_no = 0;
	static int c_so = 0;
	static int c_ea = 0;
	static int c_we = 0;

	if (err != 0)
		return (1);
	if (ft_strncmp(line, "NO ", 3) == 0)
		c_no++;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		c_so++;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		c_ea++;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		c_we++;
	if (c_no > 1 || c_so > 1 || c_ea > 1 || c_we > 1)
	   	return (error_handler(ERR_TEX_NB, NULL, 0), 1);
	if (ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "C ", 2) == 0 || ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "\n", 2) == 0)
		return (0);
	return (error_handler(ERR_INV_FILE, NULL, 0), 1);
}

void	check_data_error(char *sterr, int err)
{
	if (err == 1)
		error_handler(sterr, NULL, 0);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

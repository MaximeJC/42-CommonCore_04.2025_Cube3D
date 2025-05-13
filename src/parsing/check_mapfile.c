/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:09 by nicolmar          #+#    #+#             */
/*   Updated: 2025/05/13 11:38:10 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Le fichier doit finir absolument par .cub

int	check_mapfile(char *str)
{
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".cub", 5) != 0)
	{
		ft_putendl_fd(ERR_MAP_FILE, 2);
		return (1);
	}
	return (0);
}

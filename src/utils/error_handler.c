/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:37 by nicolmar          #+#    #+#             */
/*   Updated: 2025/05/13 11:38:38 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler(char *msg, t_data *data, int i_exit)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (i_exit)
	{
		clear_data(data);
		exit(1);
	}
}

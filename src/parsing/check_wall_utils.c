/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:11 by nicolmar          #+#    #+#             */
/*   Updated: 2025/05/13 11:38:12 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_around(char **c_map, t_data *data, int i, int j);

char	**ft_strtab_dup(char **tab)
{
	int		i;
	char	**t_tab;

	i = 0;
	t_tab = ft_calloc((ft_strtab_size(tab) + 1), sizeof(char *));
	if (!t_tab)
		return (NULL);
	while (tab[i])
	{
		t_tab[i] = ft_strdup(tab[i]);
		if (!t_tab[i])
			return (ft_strtab_free(t_tab), NULL);
		i++;
	}
	t_tab[i] = NULL;
	return (t_tab);
}

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putendl_fd(tab[i], 1);
		i++;
	}
	ft_putendl_fd("", 1);
	return ;
}

void	get_size_map(t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	data->d_map->height = ft_strtab_size(data->d_map->map);
	while (data->d_map->map[i])
	{
		if (ft_strlen(data->d_map->map[i]) > len)
			len = ft_strlen(data->d_map->map[i]);
		i++;
	}
	data->d_map->width = len;
}

int	check_carac(char **c_map, t_data *data)
{
	int	i;
	int	j;
	int	f_err;

	i = -1;
	f_err = 0;
	while (c_map[++i])
	{
		j = -1;
		while (c_map[i][++j])
		{
			f_err = check_around(c_map, data, i, j);
			if (f_err >= 1)
				return (error_handler(ERR_CHAR, NULL, 0), 1);
		}
	}
	return (0);
}

int	check_around(char **c_map, t_data *data, int i, int j)
{
	int	f_err;

	f_err = 0;
	if (!ft_isinset(c_map[i][j], " 1") && i == 0)
		f_err++;
	else if (!ft_isinset(c_map[i][j], " 1")
		&& ft_isinset(c_map[i - 1][j], " \0"))
		f_err++;
	if (!ft_isinset(c_map[i][j], " 1")
		&& i == data->d_map->height - 1)
		f_err++;
	else if (!ft_isinset(c_map[i][j], " 1")
		&& ft_isinset(c_map[i + 1][j], " \0"))
		f_err++;
	if (!ft_isinset(c_map[i][j], " 1") && j == 0)
		f_err++;
	else if (!ft_isinset(c_map[i][j], " 1")
		&& ft_isinset(c_map[i][j - 1], " \0"))
		f_err++;
	if (!ft_isinset(c_map[i][j], " 1") && j == data->d_map->width - 1)
		f_err++;
	else if (!ft_isinset(c_map[i][j], " 1")
		&& ft_isinset(c_map[i][j + 1], " \0"))
		f_err++;
	return (f_err);
}

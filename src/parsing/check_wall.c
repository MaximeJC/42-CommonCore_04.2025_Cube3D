#include "cub3d.h"

char	**ft_strtab_dup(char **tab);
void ft_print_tab(char **tab);
void set_player_data(char c, t_data *data, int y, int x);
int	find_player_pose(char **c_map, t_data *data);

int	check_wall_and_ground(t_data *data)
{
	int		d_x;
	int		d_y;
	char	**c_map;

	c_map = ft_strtab_dup(data->d_map->map);
	if(!c_map)
		return(error_handler(ERR_MALLOC, NULL, 0), 1);
	if (find_player_pose(c_map, data) != 0)
		return (ft_strtab_free(c_map), 1);
	return (ft_strtab_free(c_map), 0);
}
int	find_player_pose(char **c_map, t_data *data)
{
	int	i;
	int	j;
	int	p_nbr;

	i = 0;
	j = 0;
	p_nbr = 0;	
	while (c_map[i])
	{
		j = 0;
		while(c_map[i][j])
		{
			if (ft_isinset(c_map[i][j], "NSEW") && p_nbr == 0)
			{
				p_nbr++;
				set_player_data(c_map[i][j], data, i, j);
			}
			j++;
		}
		i++;
	}
	if (p_nbr > 1)
		return (error_handler(ERR_TM_PLY, NULL, 0), 1);
	if (p_nbr <= 0)
		return (error_handler(ERR_NE_PLY, NULL, 0), 1);
	return (0);
}

void	set_player_data(char c, t_data *data, int y, int x)
{
	data->player->pos_x = x;
	data->player->pos_y = y;

	if (c == 'N')
	{
		data->player->dir_x = 0; 
		data->player->dir_y = -1; 
	}
	else if (c == 'S')
	{
		data->player->dir_x = 0; 
		data->player->dir_y = 1; 
	}
	else if (c == 'E')
	{
		data->player->dir_x = 1; 
		data->player->dir_y = 0; 
	}
	else if (c == 'W')
	{
		data->player->dir_x = -1; 
		data->player->dir_y = 0; 
	}
}


char	**ft_strtab_dup(char **tab)
{
	int		i;
	char	**t_tab;

	i = 0;
	t_tab = ft_calloc((ft_strtab_size(tab) + 1), sizeof(char *));
	if (!t_tab)
		return (NULL);
	while(tab[i])
	{
		t_tab[i] = ft_strdup(tab[i]);
		if (!t_tab[i])
			return(ft_strtab_free(t_tab), NULL);
		i++;
	}
	t_tab[i] = NULL;
	return (t_tab);
}

void ft_print_tab(char **tab)
{
	int i;
	
	i = 0;
	while(tab[i])
	{
		ft_putendl_fd(tab[i], 1);
		i++;
	}
	ft_putendl_fd("", 1);

	return ;
}

#include "cub3d.h"

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

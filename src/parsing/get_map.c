#include "cub3d.h"

char	*ft_strdup_no_null(const char *src, size_t size);
char	**ft_lst_to_maptab(t_list *lst, size_t size);
int		get_max_len(t_list *l_map);

int	get_map(t_data *data, char **line, int fd)
{
	int		i;
	t_list	*l_map;

	i = 0;
	l_map = NULL;
	while (*line && ft_strncmp(*line, "\n", 2) == 0)
	{
		free(*line);
		*line = get_next_line(fd);
	}
	while (*line)
	{
		ft_lstadd_back(&l_map, ft_lstnew(ft_strdup(*line)));
		if (l_map == NULL)
			return (ft_putendl_fd(ERR_MALLOC, 2), 1);
		free(*line);
		*line = get_next_line(fd);
	}
	data->d_map->map = ft_lst_to_maptab(l_map, get_max_len(l_map));
	return (0);
}

int	get_max_len(t_list *l_map)
{
	t_list	*current;
	size_t	max_size;

	current = l_map;
	max_size = 0;
	while (current)
	{
		max_size = ft_max(ft_strlen(ft_strtrim((char *)current->content,
						"\n")), max_size);
		current = current->next;
	}
	return (max_size);
}

char	**ft_lst_to_maptab(t_list *lst, size_t size)
{
	char	**str_tab;
	int		i;
	t_list	*el;
	char	*str;

	el = lst;
	i = 0;
	str_tab = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (str_tab)
	{
		while (el)
		{
			str = ft_strdup_no_null((char *)el->content, size);
			if (!str)
				break ;
			str_tab[i] = str;
			str = NULL;
			i++;
			el = el->next;
		}
		str_tab[i] = NULL;
	}
	return (str_tab);
}

char	*ft_strdup_no_null(const char *src, size_t size)
{
	size_t	i;
	char	*dest;

	dest = NULL;
	dest = malloc((size + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	ft_memset(dest, ' ', size);
	dest[size] = '\0';
	while (src[i] != '\0' && src[i] != '\n' && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks_utils_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:15:15 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/13 19:15:17 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc ((ft_strlen((char *)s) + 1) * sizeof (char));
	if (!p)
		return (NULL);
	while (*s != 0)
	{
		p[i] = *s;
		s++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	map_height1(char *filename)
{
	int		fd;
	int		map_height;
	char	*map_line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	map_height = 1;
	map_line = get_next_line(fd);
	if (!map_line)
		return (0);
	while (map_line)
	{
		if (strchr(map_line, '\n') != NULL)
			map_height++;
		free(map_line);
		map_line = get_next_line(fd);
	}
	free(map_line);
	close(fd);
	return (map_height);
}

char	**map_read(t_data *data)
{
	int		fd;
	char	*map_line;
	int		i;
	char	**map_array;

	fd = open(data->filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error:\n File not found\n"), NULL);
	i = 0;
	if (data->map_height < 1)
		return (ft_printf("Error:\n No Map!\n"), NULL);
	map_array = (char **)malloc((data->map_height + 1) * sizeof(char *));
	if (!map_array)
		return (0);
	while (i < data->map_height)
	{
		map_line = get_next_line(fd);
		if (!map_line)
			break ;
		map_array[i] = ft_strdup(map_line);
		free(map_line);
		i++;
	}
	map_array[i] = NULL;
	return (close(fd), map_array);
}

int	find_last(char	**map_array)
{
	int	i;
	int	j;

	j = find_map_length(map_array);
	i = 0;
	while (map_array[i][j + 1])
		i++;
	return (i);
}

void	ft_free_map(char	**map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
	{
		free(map_array[i]);
		i++;
	}
	free(map_array);
}

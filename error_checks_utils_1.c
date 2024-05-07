/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:13:42 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/13 19:13:45 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	find_map_length(char	**map_array)
{
	int	i;

	i = 0;
	if (!map_array)
		return (0);
	while (map_array[0][i] != '\n' && map_array[0][i] != '\0')
		i++;
	return (i - 1);
}

int	**get_c_pos(char **map_array, int **c_pos, int count_c, int map_height)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < count_c)
	{
		c_pos[i] = malloc(sizeof(int) * 2);
		if (!c_pos[i])
			return (ft_printf("Error:\n allocating memory for c_pos\n"), NULL);
		x = find_start_x(map_array, map_height, 'C');
		y = find_start_y(map_array, map_height, 'C');
		if (x == -1 || y == -1)
			return (ft_printf("Error:\n finding coordinates for 'C'\n"), NULL);
		c_pos[i][0] = x;
		c_pos[i][1] = y;
		map_array[y][x] = '0';
		i++;
	}
	return (c_pos);
}

int	rectangular_check(char	**map_array, int collum_length, int last_row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < last_row)
	{
		if (map_array[i] == NULL)
			return (0);
		while (map_array[i][j] != '\n' && map_array[i][j] != '\0')
			j++;
		if (j != collum_length)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	wall_check(char	**map_array, int last_row, int collum_length)
{
	int	i;
	int	j;

	i = 0;
	j = find_map_length(map_array);
	while (map_array[i][collum_length + 1])
	{
		j = 0;
		while (map_array[i][j] != '\n' && map_array[i][j] != '\0')
		{
			if (map_array[0][j] != '1' && j <= collum_length)
				return (ft_printf("Error:\n Map not surrounded by walls\n"), 0);
			if (map_array[last_row - 1][j] != '1')
				return (ft_printf("Error:\n Map not surrounded by walls\n"), 0);
			if (map_array[i][0] != '1' && j <= collum_length)
				return (ft_printf("Error:\n Map not surrounded by walls\n"), 0);
			if (map_array[i][collum_length] != '1' && j <= collum_length)
				return (ft_printf("Error:\n Map not surrounded by walls\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_characters(char	**map_array, int last_row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < last_row)
	{
		while (map_array[i][j] != '\n' && map_array[i][j] != '\0')
		{
			if (map_array[i][j] != '0' && map_array[i][j] != '1' && \
				map_array[i][j] != 'C' \
				&& map_array[i][j] != 'P' && map_array[i][j] != 'E')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

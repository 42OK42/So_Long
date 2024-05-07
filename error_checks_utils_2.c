/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:15:01 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/13 19:15:02 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	solveable_utils(int x, int y, int *finish_cor)
{
	if ((x + 1 == finish_cor[0] && y == finish_cor[1]) || \
		(x - 1 == finish_cor[0] && y == finish_cor[1]) || \
		(x == finish_cor[0] && y + 1 == finish_cor[1]) || \
		(x == finish_cor[0] && y - 1 == finish_cor[1]))
		return (1);
	return (0);
}

int	solveable(t_data *data, int x, int y, int *finish_cor)
{
	data->successful = 0;
	if (solveable_utils(x, y, finish_cor))
		return (1);
	if (direction_checker(data, x + 1, y) == 1)
	{
		data->map_array[y][x] = '2';
		data->successful = solveable(data, x + 1, y, finish_cor);
	}
	if (!data->successful && direction_checker(data, x - 1, y) == 1)
	{
		data->map_array[y][x] = '2';
		data->successful = solveable(data, x - 1, y, finish_cor);
	}
	if (!data->successful && direction_checker(data, x, y + 1) == 1)
	{
		data->map_array[y][x] = '2';
		data->successful = solveable(data, x, y + 1, finish_cor);
	}
	if (!data->successful && direction_checker(data, x, y - 1) == 1)
	{
		data->map_array[y][x] = '2';
		data->successful = solveable(data, x, y - 1, finish_cor);
	}
	return (data->successful);
}

int	direction_checker(t_data *data, int x, int y)
{
	if (y >= 0 && (data->map_array[y][x] == \
		'0' || data->map_array[y][x] == 'C'))
		return (1);
	return (0);
}

int	find_start_x(char	**map_array, int map_height, char goal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map_height)
	{
		while (map_array[y][x] != '\n' && map_array[y][x] != '\0')
		{
			if (map_array[y][x] == goal)
				return (x);
			x++;
		}
		y++;
		x = 0;
	}
	return (-1);
}

int	find_start_y(char	**map_array, int map_height, char goal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map_height)
	{
		while (map_array[y][x] != '\n' && map_array[y][x] != '\0')
		{
			if (map_array[y][x] == goal)
				return (y);
			x++;
		}
		y++;
		x = 0;
	}
	return (-1);
}

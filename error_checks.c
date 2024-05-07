/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:11:37 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/13 19:11:40 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	error_check4(t_data	*data)
{
	int	e_cor[2];

	e_cor[0] = find_start_x(data->map_array, data->map_height, 'E');
	e_cor[1] = find_start_y(data->map_array, data->map_height, 'E');
	if (solveable(data, find_start_x(data->map_array, data->map_height, 'P'), \
			find_start_y(data->map_array, data->map_height, 'P'), e_cor) != 1)
	{
		ft_printf("Error:\n End not reachable\n");
		ft_free_map(data->map_array);
		return (0);
	}
	ft_free_map(data->map_array);
	return (1);
}

int	c_checks(t_data *data)
{
	int	i;
	int	**c_pos;

	c_pos = malloc (sizeof (int *) * data->final_coin_count);
	c_pos = get_c_pos(data->map_array, c_pos, \
	data->final_coin_count, data->map_height);
	i = 0;
	ft_free_map(data->map_array);
	while (i < data->final_coin_count)
	{
		data->map_array = map_read(data);
		if (solveable(data, find_start_x(data->map_array, \
		data->map_height, 'P'), find_start_y(data->map_array, \
		data->map_height, 'P'), c_pos[i]) != 1)
		{
			free_c_pos(data, c_pos);
			ft_free_map(data->map_array);
			return (ft_printf("Error:\n Not all collectibles reachable\n"), 0);
		}
		i++;
		ft_free_map(data->map_array);
	}
	data->map_array = map_read(data);
	free_c_pos(data, c_pos);
	return (1);
}

int	error_check3(t_data	*data)
{
	int	result;

	if (c_checks(data) == 0)
		return (0);
	result = error_check4(data);
	return (result);
}

int	error_check2(t_data	*data)
{
	int		result;

	if (count_in_map(data->map_array, 'P') != 1)
	{
		ft_printf("Error:\n Not one starting position\n");
		ft_free_map(data->map_array);
		return (0);
	}
	if (count_in_map(data->map_array, 'E') != 1)
	{
		ft_printf("Error:\n Not one Exit\n");
		ft_free_map(data->map_array);
		return (0);
	}
	if (data->final_coin_count < 1)
	{
		ft_printf("Error:\n No collectibles\n");
		ft_free_map(data->map_array);
		return (0);
	}
	result = error_check3(data);
	return (result);
}

int	error_check(t_data	*data)
{
	int		result;

	if (rectangular_check(data->map_array, \
	data->collum_length + 1, data->map_height) != 1)
	{
		ft_printf("Error:\n Map not rectangular\n");
		ft_free_map(data->map_array);
		return (0);
	}
	if (wall_check(data->map_array, data->map_height, data->collum_length) != 1)
	{
		ft_free_map(data->map_array);
		return (0);
	}
	if (valid_characters(data->map_array, data->map_height) != 1)
	{
		ft_printf("Error:\n Not all Characters valid\n");
		ft_free_map(data->map_array);
		return (0);
	}
	result = error_check2(data);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:47:53 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/16 18:47:57 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_player_left(t_data *data, int x, int y)
{
	if (move_possible(data, x - 1, y) == 1)
	{
		if (data->map_array[y][x - 1] == 'C')
			data->current_coin_count += 1;
		data->map_array[y][x] = '0';
		data->map_array[y][x - 1] = 'P';
		data->move_count++;
		ft_printf("Moves done: %i\n", data->move_count);
	}
}

void	move_player_right(t_data *data, int x, int y)
{
	if (move_possible(data, x + 1, y) == 1)
	{
		if (data->map_array[y][x + 1] == 'C')
			data->current_coin_count += 1;
		data->map_array[y][x] = '0';
		data->map_array[y][x + 1] = 'P';
		data->move_count++;
		ft_printf("Moves done: %i\n", data->move_count);
	}
}

void	move_player_up(t_data *data, int x, int y)
{
	if (move_possible(data, x, y - 1) == 1)
	{
		if (data->map_array[y - 1][x] == 'C')
			data->current_coin_count += 1;
		data->map_array[y][x] = '0';
		data->map_array[y - 1][x] = 'P';
		data->move_count++;
		ft_printf("Moves done: %i\n", data->move_count);
	}
}

void	move_player_down(t_data *data, int x, int y)
{
	if (move_possible(data, x, y + 1) == 1)
	{
		if (data->map_array[y + 1][x] == 'C')
			data->current_coin_count += 1;
		data->map_array[y][x] = '0';
		data->map_array[y + 1][x] = 'P';
		data->move_count++;
		ft_printf("Moves done: %i\n", data->move_count);
	}
}

void	update_player_position(t_data *data, char c)
{
	int	x;
	int	y;

	y = find_start_y(data->map_array, (data->map_height + 1), 'P');
	x = find_start_x(data->map_array, (data->map_height + 1), 'P');
	if (c == 'l') 
		move_player_left(data, x, y);
	else if (c == 'r')
		move_player_right(data, x, y);
	else if (c == 'u')
		move_player_up(data, x, y);
	else if (c == 'd')
		move_player_down(data, x, y);
	put_images(data);
}

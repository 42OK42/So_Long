/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_position_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:03:50 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/16 19:03:54 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	move_possible(t_data	*data, int x, int y)
{
	if (data->map_array[y][x] == 'E' && \
	data->current_coin_count == data->final_coin_count)
	{
		ft_printf("You won!\n");
		close_window(data);
		return (1);
	}
	if (data->map_array[y][x] == '0')
		return (1);
	if (data->map_array[y][x] == 'C')
		return (1);
	return (0);
}

int	on_press(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		close_window(data);
		return (0);
	}
	else if (keycode == 0 || keycode == 97)
		update_player_position(data, 'l');
	else if (keycode == 2 || keycode == 100)
		update_player_position(data, 'r');
	else if (keycode == 1 || keycode == 115)
		update_player_position(data, 'd');
	else if (keycode == 13 || keycode == 119)
		update_player_position(data, 'u');
	return (0);
}

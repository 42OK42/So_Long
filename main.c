/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:06:18 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/16 19:06:21 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

// check for forbiden functions

int	initialise_values(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		return (ft_printf("Wrong usage!"), 0);
	data->filename = argv[1];
	data->map_height = map_height1(data->filename);
	if (data->map_height < 1)
		return (ft_printf("Error: No Map!"), 0);
	data->map_array = map_read(data);
	if (data->map_array == NULL)
		return (0);
	data->collum_length = find_map_length(data->map_array);
	if (rectangular_check(data->map_array, \
		data->collum_length, data-> map_height) == 1)
		data->last_collum = find_last(data->map_array);
	data->final_coin_count = count_in_map(data->map_array, 'C');
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (initialise_values(argc, argv, &data) == 0)
		return (0);
	if (error_check(&data) == 1)
	{
		data.map_array = map_read(&data);
		data.current_coin_count = 0;
		data.move_count = 0;
		data.mlx = mlx_init();
		data.mlx_win = open_window(data.mlx, data.map_height -1, \
		data.map_array);
		data = get_images(data.mlx, &data);
		put_images(&data);
		mlx_hook(data.mlx_win, 2, (1L << 0), on_press, &data);
		mlx_hook(data.mlx_win, 17, 0, close_window, &data);
		mlx_loop(data.mlx);
	}
	return (1);
}

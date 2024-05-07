/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:55:21 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/16 18:55:28 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	destroy_map(t_data *data, char **map_array, int map_height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= map_height)
	{
		while (map_array[y][x] != '\n' && map_array[y][x] != '\0')
		{
			if (map_array[y][x] == '1')
				mlx_destroy_image(data->mlx, data->img_wall);
			if (map_array[y][x] == '0')
				mlx_destroy_image(data->mlx, data->img_background);
			if (map_array[y][x] == 'C')
				mlx_destroy_image(data->mlx, data->img_collectible);
			if (map_array[y][x] == 'P')
				mlx_destroy_image(data->mlx, data->img_player);
			if (map_array[y][x] == 'E')
				mlx_destroy_image(data->mlx, data->img_end);
			x++;
		}
		x = 0;
		y++;
	}
}

int	close_window(void *param)
{
	t_data	*data;

	data = param;
	mlx_destroy_image(data->mlx, data->img_wall);
	mlx_destroy_image(data->mlx, data->img_background);
	mlx_destroy_image(data->mlx, data->img_collectible);
	mlx_destroy_image(data->mlx, data->img_player);
	mlx_destroy_image(data->mlx, data->img_end);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	ft_free_map(data->map_array);
	free(data->mlx);
	exit(0);
	return (0);
}

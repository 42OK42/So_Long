/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:52:57 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/16 18:53:08 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*open_window(void	*mlx, int last_collum, char	**map_array)
{
	int		i;
	void	*mlx_win;

	i = 0;
	while (map_array[0][i] != '\n' && map_array[0][i] != '\0')
		i++;
	mlx_win = mlx_new_window(mlx, (i * 100), \
	((last_collum + 1) * 100), "Hello world!");
	return (mlx_win);
}

t_data	get_images(void	*mlx, t_data *data)
{
	int	img_width;
	int	img_height;

	data->relative_path_background = "./background_100x100.xpm";
	data->relative_path_collectible = "./collectible_100x100.xpm";
	data->relative_path_end = "./end_100x100.xpm";
	data->relative_path_player = "./player_100x100.xpm";
	data->relative_path_wall = "./wall_100x100.xpm";
	img_width = 100;
	img_height = 100;
	data->img_wall = mlx_xpm_file_to_image(mlx, \
	data->relative_path_wall, &img_width, &img_height);
	data->img_player = mlx_xpm_file_to_image(mlx, \
	data->relative_path_player, &img_width, &img_height);
	data->img_end = mlx_xpm_file_to_image(mlx, \
	data->relative_path_end, &img_width, &img_height);
	data->img_collectible = mlx_xpm_file_to_image(mlx, \
	data->relative_path_collectible, &img_width, &img_height);
	data->img_background = mlx_xpm_file_to_image(mlx, \
	data->relative_path_background, &img_width, &img_height);
	return (*data);
}

void	put_images_on_window(t_data *data, int x, int y)
{
	if (data->map_array[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->img_wall, (x * 100), (y * 100));
	if (data->map_array[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->img_background, (x * 100), (y * 100));
	if (data->map_array[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->img_collectible, (x * 100), (y * 100));
	if (data->map_array[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->img_player, (x * 100), (y * 100));
	if (data->map_array[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->img_end, (x * 100), (y * 100));
}

void	put_images(t_data *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		while (data->map_array[y][x] != '\n' && data->map_array[y][x] != '\0')
		{
			put_images_on_window(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:02:09 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/17 16:02:12 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	count_in_map(char	**map_array, char c)
{
	int	result;
	int	i;
	int	j;

	result = 0;
	i = 0;
	j = 0;
	while (map_array[i])
	{
		while (map_array[i][j] != '\n' && map_array[i][j] != '\0')
		{
			if (map_array[i][j] == c)
				result++;
			j++;
		}
		j = 0;
		i++;
	}
	return (result);
}

void	free_c_pos(t_data	*data, int **c_pos)
{
	int	i;

	i = 0;
	while (i < data->final_coin_count)
	{
		free(c_pos[i]);
		i++;
	}
	free(c_pos);
}

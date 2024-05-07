/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c      				                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:15:08 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/13 19:15:10 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char	**map_array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_array[i])
	{
		ft_printf("%s", map_array[i]);
		i++;
	}
	ft_printf("\n");
}

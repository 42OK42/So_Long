/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:31:52 by okrahl            #+#    #+#             */
/*   Updated: 2023/05/09 18:49:54 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}
/*
int main(void)
{
	char c[] = "Hallo";
	printf("%zu", ft_strlen(c));
}
*/

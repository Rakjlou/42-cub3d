/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:50:06 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/23 17:51:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	absolute_value(int value)
{
	if (value < 0)
		return ((unsigned int)(value * -1));
	return ((unsigned int)(value));
}

static char	*hydrate_buffer(char *buffer, unsigned int number, int original)
{
	int	i;

	i = 10;
	ft_bzero(buffer, 12);
	while (1)
	{
		buffer[i] = (number % 10) + '0';
		if (number / 10 == 0)
			break ;
		number = number / 10;
		i--;
	}
	if (original < 0)
		buffer[--i] = '-';
	return (buffer + i);
}

char	*ft_itoa(int n)
{
	char			buffer[12];

	return (ft_strdup(hydrate_buffer((char *)buffer, absolute_value(n), n)));
}

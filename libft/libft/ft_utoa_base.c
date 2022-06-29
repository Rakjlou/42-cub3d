/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:43:44 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 01:24:49 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_utoa_base(unsigned long num, char *base, unsigned int base_size)
{
	char	buffer[64];
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (1)
	{
		buffer[i++] = base[num % base_size];
		if (num / base_size == 0)
			break ;
		num = num / base_size;
	}
	result = (char *)malloc(sizeof(char) * (i + 1));
	while (i > 0)
		result[j++] = buffer[--i];
	result[j] = '\0';
	return (result);
}

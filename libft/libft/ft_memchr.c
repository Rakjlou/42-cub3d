/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:43:15 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/23 16:16:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*cursor;

	cursor = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*cursor == (unsigned char)c)
			return (cursor);
		cursor++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:43:15 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/23 16:32:09 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	is_found(const char *big, const char *little, size_t len)
{
	if (*little == '\0')
		return (1);
	else if (len == 0 || *big != *little)
		return (0);
	else
		return (is_found(++big, ++little, --len));
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == '\0')
		return ((char *)big);
	while (*big && len)
	{
		if (is_found(big, little, len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

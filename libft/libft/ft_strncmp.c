/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:43:15 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/23 16:15:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		else if (*cs1 == '\0')
			return (0);
		cs1++;
		cs2++;
	}
	return (0);
}

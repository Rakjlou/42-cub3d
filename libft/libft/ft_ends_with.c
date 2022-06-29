/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ends_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:39:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/24 23:43:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_ends_with(char *haystack, char *needle)
{
	size_t	hlen;
	size_t	nlen;

	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	if (nlen > hlen)
		return (FALSE);
	while (42)
	{
		--hlen;
		--nlen;
		if (haystack[hlen] != needle[nlen])
			return (FALSE);
		else if (nlen == 0)
			break ;
	}
	return (TRUE);
}

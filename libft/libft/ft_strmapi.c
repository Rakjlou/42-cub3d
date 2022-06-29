/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:52:45 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/23 17:53:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*cursor;
	unsigned int	i;

	i = 0;
	res = ft_calloc(1, 1 + ft_strlen(s));
	if (res == NULL)
		return (NULL);
	cursor = res;
	while (*s)
		*cursor++ = f(i++, *s++);
	return (res);
}

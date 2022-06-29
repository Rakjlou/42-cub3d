/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:05:29 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 05:05:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	int			end;
	size_t		start;

	start = 0;
	end = ft_strlen(s) - 1;
	while (ft_strchr(set, s[start]) != NULL)
		start++;
	while (end >= 0 && ft_strchr(set, s[end]))
		end--;
	return (ft_substr(s, start, (end - start) + 1));
}

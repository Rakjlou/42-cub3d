/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:22:06 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/11 22:25:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_all(char *str, int (*check)(int c))
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!check((unsigned char)str[i]))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

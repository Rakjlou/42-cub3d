/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvalid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:23:24 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 00:58:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_cvalid(char ref, char *authorized)
{
	int	i;

	i = 0;
	while (authorized[i])
	{
		if (ref == authorized[i])
			return (TRUE);
		++i;
	}
	return (FALSE);
}

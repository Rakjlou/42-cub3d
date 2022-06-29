/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_as_cmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:30:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 21:49:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ftlst.h"

char	**lst_as_cmatrix(t_lst *lst, int duplicate)
{
	size_t	i;
	char	**result;

	result = ft_calloc(sizeof(char *), lst->size + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < lst->size)
	{
		if (duplicate)
		{
			result[i] = ft_strdup(lst_data_at(lst, i));
			if (result[i] == NULL)
				return (ft_cmatrix_free(result), NULL);
		}
		else
			result[i] = lst_data_at(lst, i);
		++i;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmatrix_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:48:53 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 22:07:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**hydrate_result(char **result, char **matrix1, char **matrix2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (matrix1 && matrix1[i])
	{
		result[j] = ft_strdup(matrix1[i]);
		if (result[j] == NULL)
			return (ft_cmatrix_free(result), NULL);
		++j;
		++i;
	}
	i = 0;
	while (matrix2 && matrix2[i])
	{
		result[j] = ft_strdup(matrix2[i]);
		if (result[j] == NULL)
			return (ft_cmatrix_free(result), NULL);
		++j;
		++i;
	}
	return (result);
}

char	**ft_cmatrix_join(char **matrix1, char **matrix2)
{
	char	**result;
	size_t	total;

	total = 0;
	if (matrix1)
		total += ft_cmatrix_size(matrix1);
	if (matrix2)
		total += ft_cmatrix_size(matrix2);
	result = ft_calloc(sizeof(char *), total + 1);
	if (result == NULL)
		return (NULL);
	return (hydrate_result(result, matrix1, matrix2));
}

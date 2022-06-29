/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmatrix_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:48:53 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 21:49:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_cmatrix_size(char **matrix)
{
	size_t	i;

	if (matrix == NULL)
		return (0);
	i = 0;
	while (matrix[i])
		++i;
	return (i);
}

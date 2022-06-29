/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmatrix_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:48:53 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/03 19:15:50 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"
#include "libft.h"

void	ft_cmatrix_print(char **matrix)
{
	int	i;

	if (matrix == NULL)
		ftprintf("(null)\n");
	else
	{
		i = 0;
		ftprintf("[\n");
		while (matrix[i])
		{
			ftprintf("\t%d => '%s'\n", i, matrix[i]);
			++i;
		}
		ftprintf("]\n");
		return ;
	}
}

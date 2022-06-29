/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 03:14:55 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/28 03:36:55 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ltoa_base(long num, char *base, unsigned int base_size)
{
	char	*answer;
	char	*positive;
	size_t	positive_size;

	if (num >= 0)
		return (ft_utoa_base(num, base, base_size));
	positive = ft_utoa_base(num * -1, base, base_size);
	positive_size = ft_strlen(positive);
	answer = ft_calloc(1, positive_size + 2);
	ft_strlcat(answer, "-", 2);
	ft_strlcat(answer, positive, positive_size + 2);
	free(positive);
	return (answer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:17:02 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 14:45:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

unsigned int	ft_umin(unsigned int a, unsigned int b)
{
	if (a <= b)
		return (a);
	return (b);
}

unsigned int	ft_uimin(unsigned int a, unsigned int b)
{
	return ((unsigned int)ft_min((int)a, (int)b));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:17:40 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/16 05:17:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

unsigned int	ft_umax(unsigned int a, unsigned int b)
{
	if (a >= b)
		return (a);
	return (b);
}

unsigned int	ft_uimax(unsigned int a, unsigned int b)
{
	return ((unsigned int)ft_max((int)a, (int)b));
}

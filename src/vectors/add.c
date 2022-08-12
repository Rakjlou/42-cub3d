/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 22:01:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

void	ivector_add(t_ivector *a, t_ivector *b, t_ivector *result)
{
	result->x = a->x + b->x;
	result->y = a->y + b->y;
}

void	dvector_add(t_dvector *a, t_dvector *b, t_dvector *result)
{
	result->x = a->x + b->x;
	result->y = a->y + b->y;
}

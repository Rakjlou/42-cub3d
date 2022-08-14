/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:53:03 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/13 20:12:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/rect.h"

void	rect_get_center(t_rect *rect, t_ivector *result)
{
	result->x = rect->start.x + ((rect->end.x - rect->start.x) / 2);
	result->y = rect->start.y + ((rect->end.y - rect->start.y) / 2);
}

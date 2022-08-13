/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/12 19:31:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_H
# define CIRCLE_H

# include "vectors.h"
# include "render/color.h"

typedef struct s_circle
{
	int				radius;
	t_ivector		origin;
	t_color			border_color;
	t_color			fill_color;
}	t_circle;

void	render_circle(t_circle *circle);

#endif

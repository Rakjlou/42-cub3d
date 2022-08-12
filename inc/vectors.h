/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/11 22:01:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct s_ivector
{
	int	x;
	int	y;
}	t_ivector;

typedef struct s_dvector
{
	double	x;
	double	y;
}	t_dvector;

void	ivector_add(t_ivector *a, t_ivector *b, t_ivector *result);
void	dvector_add(t_dvector *a, t_dvector *b, t_dvector *result);

void	ivector_mult(t_ivector *a, t_ivector *b, t_ivector *result);
void	dvector_mult(t_dvector *a, t_dvector *b, t_dvector *result);

#endif

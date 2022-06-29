/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterr_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:59:20 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 14:47:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterr.h"

void	fterr_print(void)
{
	t_fterr	*error;

	error = fterr_current();
	if (error == NULL)
		return ;
	error->print(error);
}

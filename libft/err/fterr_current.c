/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterr_current.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:51:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 13:55:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterr.h"

t_fterr	*fterr_set_current(t_fterr *error)
{
	static t_fterr	*current = NULL;

	if (error != NULL)
		current = error;
	return (current);
}

t_fterr	*fterr_current(void)
{
	return (fterr_set_current(NULL));
}

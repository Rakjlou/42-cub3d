/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterr_register.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:11:01 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 14:46:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterr.h"
#include "libft.h"
#include "ftprintf.h"
#include <stdlib.h>

static t_fterr	*fterr_new(t_fterr_code code,
	const char *message,
	void (*print)(t_fterr *))
{
	t_fterr	*error;

	error = ft_calloc(sizeof(t_fterr), 1);
	if (error == NULL)
		return (NULL);
	error->code = code;
	if (message != NULL)
		error->message = message;
	if (print != NULL)
		error->print = print;
	else
		error->print = fterr_default_print;
	return (error);
}

t_fterr	*fterr_register(
	t_fterr_code code,
	const char *message,
	void (*print)(t_fterr *))
{
	t_fterr	*error;
	t_lst	*e_list;

	e_list = fterr_get_list();
	if (e_list == NULL)
		return (NULL);
	error = fterr_new(code, message, print);
	if (error == NULL)
		return (NULL);
	if (lst_push_back(e_list, error) == 0)
		return (free(error), NULL);
	return (error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 19:49:49 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <unistd.h>

static void	print_padding(t_printf *state, size_t size)
{
	size_t	i;

	i = 0;
	while (i++ < size)
		_ftprintf_write(state, " ", 1);
}

static void	actual_print(t_printf *state, char *to_print)
{
	size_t	source_size;

	source_size = ft_strlen(to_print);
	if (state->op.length == FALSE || state->op.length_value < source_size)
	{
		_ftprintf_write(state, to_print, source_size);
		return ;
	}
	else if (state->op.justified_left == TRUE)
	{
		_ftprintf_write(state, to_print, source_size);
		print_padding(state, state->op.length_value - source_size);
	}
	else
	{
		print_padding(state, state->op.length_value - source_size);
		_ftprintf_write(state, to_print, source_size);
	}
}

void	print_string(t_printf *state)
{
	char	*to_print;

	to_print = va_arg(state->args, char *);
	if (to_print == NULL)
		to_print = NULLSTR_PLACEHOLDER;
	if (state->op.precision == TRUE)
	{
		to_print = ft_substr(to_print, 0, state->op.precision_value);
		if (to_print == NULL)
			return ;
		actual_print(state, to_print);
		free(to_print);
	}
	else
		actual_print(state, to_print);
}

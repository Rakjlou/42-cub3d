/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 19:47:51 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdlib.h>
#include <unistd.h>

static char	*apply_plus_flag(t_printf *state, int raw, char *original)
{
	char	*flagged;

	if (state->op.force_sign == FALSE || raw < 0)
		return (original);
	flagged = ft_strjoin("+", original);
	if (flagged == NULL)
		return (original);
	free(original);
	return (flagged);
}

static char	*apply_space_flag(t_printf *state, int raw, char *original)
{
	char	*flagged;

	if (state->op.blank == FALSE || state->op.force_sign == TRUE || raw < 0)
		return (original);
	flagged = ft_strjoin(" ", original);
	if (flagged == NULL)
		return (original);
	free(original);
	return (flagged);
}

static char	*apply_flags(t_printf *state, int raw, char *to_print)
{
	to_print = apply_special_cases(state, raw, to_print);
	to_print = apply_precison_flag(state, raw, to_print);
	to_print = apply_plus_flag(state, raw, to_print);
	to_print = apply_space_flag(state, raw, to_print);
	to_print = apply_length_flag(state, to_print);
	return (to_print);
}

void	print_int(t_printf *state)
{
	int		raw;
	char	*to_print;
	size_t	to_print_size;

	raw = va_arg(state->args, int);
	to_print = ft_ltoa_base(raw, "0123456789", 10);
	if (to_print == NULL)
		return ;
	to_print = apply_flags(state, raw, to_print);
	to_print_size = ft_strlen(to_print);
	_ftprintf_write(state, to_print, to_print_size);
	free(to_print);
}

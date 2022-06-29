/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 19:50:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdlib.h>
#include <unistd.h>

static char	*apply_flags(t_printf *state, unsigned int raw, char *to_print)
{
	to_print = apply_special_cases(state, (int)raw, to_print);
	to_print = apply_precison_flag(state, 1, to_print);
	to_print = apply_length_flag(state, to_print);
	return (to_print);
}

void	print_unsigned_int(t_printf *state)
{
	unsigned int	raw;
	char			*to_print;
	size_t			to_print_size;

	raw = va_arg(state->args, unsigned int);
	to_print = ft_utoa_base(raw, "0123456789", 10);
	if (to_print == NULL)
		return ;
	to_print = apply_flags(state, raw, to_print);
	to_print_size = ft_strlen(to_print);
	_ftprintf_write(state, to_print, to_print_size);
	free(to_print);
}

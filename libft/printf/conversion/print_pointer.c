/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 19:48:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdlib.h>
#include <unistd.h>

static char	*get_pointer_string(unsigned long raw)
{
	char	*hex;
	char	*ptr_str;

	if (raw == 0)
		return (ft_strdup(NULL_PLACEHOLDER));
	hex = ft_utoa_base(raw, "0123456789abcdef", 16);
	if (hex == NULL)
		return (NULL);
	ptr_str = ft_strjoin("0x", hex);
	free(hex);
	if (ptr_str == NULL)
		return (NULL);
	return (ptr_str);
}

static char	*apply_flags(t_printf *state, char *to_print)
{
	to_print = apply_length_flag(state, to_print);
	return (to_print);
}

void	print_pointer(t_printf *state)
{
	unsigned long	raw;
	char			*to_print;
	size_t			to_print_size;

	raw = va_arg(state->args, unsigned long);
	to_print = get_pointer_string(raw);
	if (to_print == NULL)
		return ;
	to_print = apply_flags(state, to_print);
	to_print_size = ft_strlen(to_print);
	_ftprintf_write(state, to_print, to_print_size);
	free(to_print);
}

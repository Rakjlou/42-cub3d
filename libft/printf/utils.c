/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:22:23 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 02:34:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "libft.h"
#include <stdlib.h>

void	cat_padding(t_printf *state, char *str, int padding_size)
{
	char	padding_character;

	if (state->op.zero_padded == TRUE
		&& state->op.justified_left == FALSE)
		padding_character = '0';
	else
		padding_character = ' ';
	while (*str)
		str++;
	while (padding_size-- > 0)
		*str++ = padding_character;
}

char	*apply_length_flag(t_printf *state, char *original)
{
	size_t	original_size;
	char	*flagged;
	int		padding_size;
	int		i;

	original_size = ft_strlen(original);
	if (state->op.length == FALSE || state->op.length_value <= original_size)
		return (original);
	i = 0;
	padding_size = state->op.length_value - original_size;
	flagged = ft_calloc(state->op.length_value + 1, sizeof(char));
	if (flagged == NULL)
		return (original);
	if ((*original == '+' || *original == '-') && state->op.zero_padded)
		flagged[i++] = *original;
	if (state->op.justified_left == TRUE)
		ft_strlcat(flagged, original + i, state->op.length_value + 1);
	cat_padding(state, flagged, padding_size);
	if (state->op.justified_left == FALSE)
		ft_strlcat(flagged, original + i, state->op.length_value + 1);
	free(original);
	return (flagged);
}

char	*apply_precison_flag(t_printf *state, int raw, char *original)
{
	char	*fl;
	char	*original_save;
	size_t	n_size;
	size_t	fl_size;

	if (state->op.precision == FALSE)
		return (original);
	original_save = original;
	if (raw < 0)
		++original;
	n_size = ft_strlen(original);
	if (n_size >= state->op.precision_value)
		return (original_save);
	fl_size = (state->op.precision_value - n_size) + n_size;
	if (raw < 0)
		++fl_size;
	fl = ft_calloc(fl_size + 1, sizeof(char));
	if (fl == NULL)
		return (original);
	else if (raw < 0)
		ft_strlcat(fl, "-", fl_size + 1);
	ft_fill_str(ft_strchr(fl, '\0'), '0', (state->op.precision_value - n_size));
	ft_strlcat(fl, original, fl_size + 1);
	free(original_save);
	return (fl);
}

char	*apply_sharp_flag(t_printf *state, char *original, char *prefix)
{
	char	*flagged;

	if (state->op.alternative == FALSE
		|| ft_strncmp(original, "0", ft_strlen(original)) == 0)
		return (original);
	flagged = ft_strjoin(prefix, original);
	if (flagged == NULL)
		return (original);
	free(original);
	return (flagged);
}

char	*apply_special_cases(t_printf *state, int raw, char *original)
{
	char	*flagged;

	if (state->op.precision == TRUE
		&& state->op.precision_value == 0 && raw == 0)
	{
		flagged = ft_calloc(1, sizeof(char));
		if (flagged == NULL)
			return (original);
		free(original);
		return (flagged);
	}
	return (original);
}

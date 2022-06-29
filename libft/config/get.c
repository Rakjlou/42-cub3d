/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:52:54 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 22:24:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftconfig.h"
#include "libft.h"
#include <limits.h>

char	**ftconfig_get(t_ftconfig *config, const char *key)
{
	t_iter	iter;
	char	**entry;

	if (config->data.size == 0)
		return (NULL);
	iter_init(&iter, &config->data, ASC);
	while (iter_next(&iter))
	{
		entry = (char **)iter.data;
		if (entry == NULL)
			continue ;
		if (ft_strncmp(entry[0], key, UINT_MAX) == 0)
			return (entry);
	}
	return (NULL);
}

char	*ftconfig_get_single(t_ftconfig *config, const char *key)
{
	char	**entry;

	entry = ftconfig_get(config, key);
	if (entry == NULL)
		return (NULL);
	return (entry[1]);
}

t_bool	ftconfig_get_boolean(t_ftconfig *config, const char *key)
{
	char	**entry;
	int		val;

	entry = ftconfig_get(config, key);
	if (entry == NULL)
		return (FALSE);
	else if (entry[1] == NULL)
		return (TRUE);
	val = ft_atoi(entry[1]);
	if (val == 1)
		return (TRUE);
	return (FALSE);
}

int	ftconfig_get_int(t_ftconfig *config, const char *key)
{
	char	**entry;

	entry = ftconfig_get(config, key);
	if (entry == NULL)
		return (0);
	return (ft_atoi(entry[1]));
}

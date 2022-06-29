/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:42:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 17:22:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftconfig.h"
#include "readf.h"
#include <stdlib.h>

static t_bool	ftconfig_readl(const char *line, void *data)
{
	t_ftconfig	*config;
	char		**entry;

	config = (t_ftconfig *)data;
	entry = ft_split(line, " \t\n\r\v\f");
	if (entry == NULL)
	{
		config->status = FTCONF_E_FAILED_MALLOC;
		return (FALSE);
	}
	else if (entry[0] == NULL)
		return (free(entry), TRUE);
	else if (lst_push_back(&config->data, entry) == 0)
	{
		config->status = FTCONF_E_FAILED_MALLOC;
		return (FALSE);
	}
	return (TRUE);
}

t_ftconfig_status	ftconfig_init(t_ftconfig *config, const char *filename)
{
	t_readf_status	status;

	ft_bzero(config, sizeof(t_ftconfig));
	status = readf(filename, ftconfig_readl, config);
	if (status == FTRF_E_FILE_OPEN)
		return (FTCONF_E_FILE_OPEN);
	return (config->status);
}

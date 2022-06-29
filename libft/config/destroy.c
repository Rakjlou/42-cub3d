/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:22:34 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 19:19:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftconfig.h"
#include <stdlib.h>
#include <stdio.h>

static void	ftconfig_destroy_entry(void *data)
{
	char	**entry;
	int		i;

	i = 0;
	if (data == NULL)
		return ;
	entry = (char **)data;
	while (entry[i] != NULL)
		free(entry[i++]);
	free(entry);
}

void	ftconfig_destroy(t_ftconfig *config)
{
	lst_destroy_nodes(&config->data, ftconfig_destroy_entry);
	ft_bzero(config, sizeof(t_ftconfig));
}

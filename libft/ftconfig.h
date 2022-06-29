/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftconfig.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:35:08 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 22:24:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTCONFIG_H
# define FTCONFIG_H

# include "ftlst.h"
# include "libft.h"

typedef enum e_ftconfig_status
{
	FTCONF_SUCCESS,
	FTCONF_E_FILE_OPEN,
	FTCONF_E_READL,
	FTCONF_E_FAILED_MALLOC
}	t_ftconfig_status;

typedef struct s_ftconfig
{
	const char			*filename;
	t_lst				data;
	t_ftconfig_status	status;
}	t_ftconfig;

/* config/get.c */
char				**ftconfig_get(t_ftconfig *config, const char *key);
char				*ftconfig_get_single(t_ftconfig *config, const char *key);
t_bool				ftconfig_get_boolean(t_ftconfig *config, const char *key);
int					ftconfig_get_int(t_ftconfig *config, const char *key);

t_ftconfig_status	ftconfig_init(t_ftconfig *config, const char *filename);
void				ftconfig_destroy(t_ftconfig *config);

#endif

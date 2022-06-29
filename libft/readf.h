/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:18:30 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 22:24:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READF_H
# define READF_H

# include "libft.h"

typedef enum e_readf_status
{
	FTRF_SUCCESS,
	FTRF_E_FILE_OPEN,
	FTRF_E_READL
}	t_readf_status;

t_readf_status	readf(
					const char *filename,
					t_bool (*readl)(const char *, void *),
					void *data);

#endif

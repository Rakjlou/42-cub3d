/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterr_default_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:23:46 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 14:47:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterr.h"
#include "libft.h"
#include "ftprintf.h"
#include <unistd.h>

void	fterr_print_ecode(t_fterr *error)
{
	ftfprintf(STDERR_FILENO, "[E%d] ", error->code);
}

void	fterr_default_print(t_fterr *error)
{
	fterr_print_ecode(error);
	ftfprintf(STDERR_FILENO, "%s\n", error->message);
}

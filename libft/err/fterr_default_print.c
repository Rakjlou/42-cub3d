/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterr_default_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:23:46 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 20:46:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterr.h"
#include "libft.h"
#include "ftprintf.h"
#include <unistd.h>

void	fterr_print_ecode(t_fterr *error)
{
	ftfprintf(STDERR_FILENO, "Error\n[E%d] ", error->code);
}

void	fterr_default_print(t_fterr *error)
{
	fterr_print_ecode(error);
	ftfprintf(STDERR_FILENO, "%s\n", error->message);
}

void	fterr_default_printf(t_fterr *error)
{
	fterr_print_ecode(error);
	ftfprintf(STDERR_FILENO, error->message, error->data);
	ftfprintf(STDERR_FILENO, "%s", "\n");
}

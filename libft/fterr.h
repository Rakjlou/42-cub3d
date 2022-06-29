/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:06:56 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 14:49:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTERR_H
# define FTERR_H

# include "ftlst.h"

typedef int		t_fterr_code;

typedef struct e_fterr
{
	t_fterr_code	code;
	const char		*message;
	void			*data;
	void			(*data_free)(void *);
	void			(*print)(struct e_fterr *);
}	t_fterr;

void	fterr_print(void);
void	fterr_print_ecode(t_fterr *error);
void	fterr_set(t_fterr_code code, void *data, void (*data_free)(void *));
void	fterr_set_error(t_fterr_code code);
void	fterr_destroy(void);
t_fterr	*fterr_register(
			t_fterr_code code,
			const char *message,
			void (*print)(t_fterr *));

/* Those are internals, they should be considered private */
void	fterr_default_print(t_fterr *error);
t_fterr	*fterr_set_current(t_fterr *error);
t_fterr	*fterr_current(void);
t_lst	*fterr_get_list(void);
t_fterr	*fterr_get(t_fterr_code code);

#endif

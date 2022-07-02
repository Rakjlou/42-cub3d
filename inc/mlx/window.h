/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:55:44 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/01 15:19:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "libft/bool.h"

typedef struct s_window
{
	int		height;
	int		length;
	char	*title;
	void	*raw;
}	t_window;

t_bool	window_set_key_callback(int (*callback)(int));
t_bool	window_set_mouse_callback(int (*callback)(int, int, int));
t_bool	window_set_expose_callback(int (*callback)(void));
t_bool	window_set_close_callback(int (*callback)(void));

#endif

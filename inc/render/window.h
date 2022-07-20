/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:55:44 by nsierra-          #+#    #+#             */
/*   Updated: 2022/07/21 00:04:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define WINDOW_HEIGHT 360
# define WINDOW_WIDTH 360
# define WINDOW_TITLE "Louveteau Trois Dimensions"

# include "bool.h"

typedef struct s_window
{
	int		height;
	int		length;
	char	*title;
	void	*core;
	void	*mlx;
}	t_window;

t_window	*_window(void);

t_bool		window_init(void);
void		window_destroy(void);

t_bool		window_set_key_callback(int (*callback)(int));
t_bool		window_set_mouse_callback(int (*callback)(int, int, int));
t_bool		window_set_expose_callback(int (*callback)(void));
t_bool		window_set_close_callback(int (*callback)(void));

#endif

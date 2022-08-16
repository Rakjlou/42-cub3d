/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:55:44 by nsierra-          #+#    #+#             */
/*   Updated: 2022/08/15 21:53:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1500
# define WINDOW_TITLE "Macaque & Double Whooper"

# define KEY_ESCAPE 65307
# define KEY_FORWARD 119
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_BACKWARD 115
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_RIGHT 65363

# include "bool.h"
# include "vectors.h"
# include "render/color.h"

typedef struct s_window
{
	char		*title;
	void		*core;
	void		*mlx;
	void		*buffer_image;
	char		*buffer;
	int			depth;
	int			line_size;
	int			endian;
	t_ivector	center;
	t_bool		enable_transparency;
}	t_window;

t_window	*_window(void);

t_bool		window_init(void);
void		window_destroy(void);
void		window_refresh(void);

void		window_set_pixel(int line, int column, t_color color);
t_color		*window_get_pixel(int line, int column);

void		window_set_keydown_callback(int (*callback)(int));
void		window_set_keyup_callback(int (*callback)(int));
void		window_set_mouse_click_callback(int (*callback)(int, int, int));
void		window_set_expose_callback(int (*callback)(void));
void		window_set_close_callback(int (*callback)(void));
void		window_set_loop_callback(int (*callback)(void));

#endif

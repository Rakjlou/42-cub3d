/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:36:16 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 21:38:55 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define CONVERSION_CHARACTER '%'
# define FLAGS " +-0#"
# define CONV_SPECIFIERS "cspdiuxX%"
# define STATE_DEFAULT 0
# define STATE_CONVERSION_FLAGS 1
# define STATE_CONVERSION_LENGTH 2
# define STATE_CONVERSION_PRECISION 3
# define STATE_CONVERSION_PRINT 4
# define STATE_WRONG_FLAG 5
# define STATE_END 6

# ifdef __APPLE__
#  define NULL_PLACEHOLDER "0x0"
#  define NULLSTR_PLACEHOLDER "(null)"
# else
#  define NULL_PLACEHOLDER "(nil)"
#  define NULLSTR_PLACEHOLDER "(null)"
# endif

# include <unistd.h>

typedef struct s_printf_op
{
	t_bool		alternative;
	t_bool		zero_padded;
	t_bool		justified_left;
	t_bool		blank;
	t_bool		force_sign;
	t_bool		precision;
	t_bool		length;
	size_t		precision_value;
	size_t		length_value;
	char		type;
	const char	*start;
}	t_printf_op;

typedef struct s_printf
{
	const char		*(*callback[6])(const char *, struct s_printf *);
	va_list			args;
	int				bytes_printed;
	unsigned int	current;
	t_printf_op		op;
	int				fd;
	char			*wbuf;
	size_t			wbuf_size;
	unsigned int	wbuf_cursor;
}	t_printf;

int			ftfprintf(int fd, const char *format, ...);
int			ftsprintf(char *buffer, size_t size, const char *format, ...);
int			ftprintf(const char *format, ...)
			__attribute__((__format__ (__printf__, 1, 2)));

void		_ftprintf_write(t_printf *state, const char *str, size_t len);

/* STATES */
const char	*state_default(const char *format, t_printf *state);
const char	*state_conversion(const char *format, t_printf *state);
const char	*state_conversion_flags(const char *format, t_printf *state);
const char	*state_conversion_length(const char *format, t_printf *state);
const char	*state_conversion_precision(const char *format, t_printf *state);
const char	*state_conversion_print(const char *format, t_printf *state);
const char	*state_wrong_flag(const char *format, t_printf *state);

/* CONVERSIONS */
void		print_character(t_printf *state);
void		print_string(t_printf *state);
void		print_pointer(t_printf *state);
void		print_int(t_printf *state);
void		print_unsigned_int(t_printf *state);
void		print_hex_lowercase(t_printf *state);
void		print_hex_uppercase(t_printf *state);
void		print_flag(t_printf *state);

/* UTILS */
char		*apply_length_flag(t_printf *state, char *original);
char		*apply_sharp_flag(t_printf *state, char *original, char *prefix);
char		*apply_precison_flag(t_printf *state, int raw, char *original);
char		*apply_special_cases(t_printf *state, int raw, char *original);

void		cat_padding(t_printf *state, char *str, int padding_size);

#endif

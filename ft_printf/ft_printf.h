/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:22:22 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/10 13:53:54 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#include <stdarg.h>

#include "libft/src/libft.h"

#include <stdio.h> // weghalen

typedef	struct	s_track
{
	char		*value;
	char		type;
	t_bool		lalign;
	char		space;
	int			width;
	int			prec;
}				t_track;

void	ft_printf(const char *, ...);

int		flaghandler(t_track *c, const char *str, va_list args);

void	t_track_init(t_track *c);

int		value_converter(va_list args, t_track *c);

char	*ft_itoa_ptr(unsigned long long n);

int		value_formatter(t_track *c);

#	endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:22:22 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/11 16:48:05 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#include <stdarg.h>

#include "libft/libft.h"

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

int		ft_printf(const char *, ...);

int		flaghandler(t_track *c, const char *str, va_list args);

void	t_track_init(t_track *c);

int		value_converter(va_list args, t_track *c);

char	*ft_itoa_ptr(unsigned long long n);

int		value_formatter(t_track *c);

int		value_output_combiner(char **output, t_track *c, size_t *len);

void	print_string(char *output, size_t len);

#	endif
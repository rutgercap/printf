/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:22:22 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/05 12:21:42 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#include <stdarg.h>

#include "libft/src/libft.h"

#include <stdio.h> // weghalen

void	ft_printf(const char *, ...);

char	*arg_to_ascii(char c, va_list args);

typedef	struct	Flags
{
	char		*value;
	char		type;
	t_bool		align;	// is er een manier om dit standaard op false te zetten? 
	char		space;
	int			width;
	int			prec;
}				Flags;

#	endif
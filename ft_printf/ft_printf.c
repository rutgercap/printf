/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:22:19 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/01 16:07:40 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/src/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	ft_printf(const char *str, ...)
{
	va_list args;

	if (!str)
		return ;
	va_start(args, str);
	return ;
	va_end(args);
}

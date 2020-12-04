/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arghandlers.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 15:01:13 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/04 15:22:18 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/src/libft.h"
#include "ft_printf.h"

char	*arg_to_ascii(char c, va_list args)
{
	char	*ret;

	ret = NULL;
	if (c == '%')
	{
		ret = malloc(1);
		if (*ret)
			ret[0] = '%';
	}
	// else if (c == 'i')
	// 	ret = integer(args);
	// else if (c == 's')
	// 	ret = string(args);
	// else if (c == 'c')
	// 	ret = character(args);
	// else if (c == 'p')
	// 	ret = pointer(args);
	// else if (c == 'd')
	// 	ret = digit(args);
	// else if (c == 'x' || c == 'X')
	// 	ret = hexa(args, c);
	return (ret);
}
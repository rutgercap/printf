/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 11:48:33 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/10 12:11:07 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		string_converter(va_list args, t_track *c)
{
	char	*temp;

	temp = va_arg(args, char*);
	c->value = ft_substr(temp, 0, ft_strlen(temp));
	if (!c->value)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int 	int_converter(va_list args, t_track *c)
{
	c->value = ft_itoa(va_arg(args, int));
	if (!c->value)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int		uns_int_converter(va_list args, t_track *c)
{
	unsigned int	temp;

	temp = va_arg(args, unsigned int);
	if (c->type == 'u')
		c->value = ft_itoa((unsigned long)temp);
	else if (c->type == 'x')
		c->value = ft_itoa_base(temp, "0123456789abcdef");
	else 
		c->value = ft_itoa_base(temp, "0123456789ABCDEF");
	if (!c->value)
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int		pointer_converter(va_list args, t_track *c)
{
	c->value = ft_itoa_ptr(va_arg(args, unsigned long long));
	if (!c->value)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		value_converter(va_list args, t_track *c)
{
	int ret;

	ret = 1;
	if (c->type == '%' || c->type == 'c')
	{
		c->value = ft_calloc(2, 1);
		if (!c->value)
			return (EXIT_FAILURE);
		c->value[0] = (c->type == 'c') ? va_arg(args, int) : '%';
	}
	else if (c->type == 'i' || c->type == 'd')
		ret = int_converter(args, c);
	else if (c->type == 's')
		ret = string_converter(args, c);
	else if (c->type == 'x' || c->type == 'X' || c->type == 'u')
		ret = uns_int_converter(args, c);
	else if (c->type == 'p')
		ret = pointer_converter(args, c);
	return (ret);
}

// xX%
// i d u c s p 

// b ft_printf.c:43

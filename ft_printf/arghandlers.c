/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arghandlers.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 15:01:13 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/05 14:12:50 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_reader(Flags *c, char *str, va_list args)
{
	size_t	i;
	char	*types;

	types = "cspdiuxX%";
	i = 0;
	c->align = (str[i] == '-') ? TRUE : FALSE;
	if (str[i] == '-')
		i++;
	if (str[i] == ' ' || str[i] == 0)
		c->space = str[i]; 
	if (ft_isdigit(str[i]) || str[i] == '*')			// implement *
		c->width = (str[i] == '*') ? args : ft_atoi(*str + i);
	while(ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		i++;
		c->prec = (str[i] == '*') ? args : ft_atoi(*str + i);
	}
	while(ft_isdigit(str[i]))
		i++;
	if (ft_strchr(types, str[i]) != NULL)
		return (i);
	return (0);
}
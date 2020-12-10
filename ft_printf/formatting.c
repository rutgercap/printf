/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formatting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 11:37:27 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/10 14:09:57 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_formatting(t_track *c)
{
	char	*temp;

	if ((int)ft_strlen(c->value) != c->prec)
	{
		temp = ft_calloc(c->prec + 1, 1);
		if (!temp)
			return (EXIT_FAILURE);
		if (c->type == 's')
			ft_memcpy(temp, c->value, c->prec);
		else
		{
			if (c->value[0] == '-')
			{
				c->prec++;
				c->value[0] = '0';
			}
			ft_memset(temp, '0', c->prec);
			temp[0] = (c->value[0] == '-') ? '-' : '0';
			ft_strlcpy(temp + (c->prec - ft_strlen(c->value)),
			c->value, c->prec);
		}
		free(c->value);
		c->value = temp;
	}
	return (EXIT_SUCCESS);
}

int		width_formatting(char **temp, t_track *c)
{
	if ((int)ft_strlen(c->value) < c->width)
	{
		temp = ft_calloc(c->width + 1, 1);
		if (!temp)
			return (EXIT_FAILURE);
		ft_memset(temp, c->space, c->width);
	}
	return (EXIT_SUCCESS);
}

int		value_formatter(t_track *c)
{
	int		error;
	char	*temp;

	error = 0;
	if (c->prec >= 0)
		error = prec_formatting(c);
	if (c->width >= 0)
		error = width_formatting(&temp, c);
	if (error)
		free(c->value);
	return (error);
}

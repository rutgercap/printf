/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formatting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 11:37:27 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/11 11:48:57 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*number_precision(char *temp, t_track c)
{
	char		*index;

	ft_memset(temp, '0', c.prec);
	if (c.value[0] == '-')
	{
		temp[0] = '-';
		c.value++;
	}
	index = temp + (c.prec - ft_strlen(c.value));
	ft_strlcpy(index, c.value, c.prec);
	return (temp);
}

int		prec_formatting(t_track *c)
{
	char	*temp;

	if (c->value[0] == '-' && c->type != 's')
		c->prec++;
	if ((int)ft_strlen(c->value) != c->prec)
	{
		temp = ft_calloc(c->prec + 1, 1);
		if (!temp)
			return (EXIT_FAILURE);
		if (c->type == 's')
			ft_memcpy(temp, c->value, c->prec);
		else
			temp = number_precision(temp, *c);
		free(c->value);
		c->value = temp;
	}
	return (EXIT_SUCCESS);
}

int		width_formatting(t_track *c)
{
	char	*temp;
	char	*index;

	if ((int)ft_strlen(c->value) < c->width)
	{
		temp = ft_calloc(c->width + 1, 1);
		if (!temp)
			return (EXIT_FAILURE);
		ft_memset(temp, c->space, c->width);
		index = temp;
		if (c->lalign == FALSE)
			index = temp + (c->width - ft_strlen(c->value));
		ft_strlcpy(index, c->value, c->width);
		free(c->value);
		c->value = temp;
	}
	return (EXIT_SUCCESS);
}

int		value_formatter(t_track *c)
{
	int		error;

	error = 0;
	if (c->prec >= 0)
		error = prec_formatting(c);
	if (c->width >= 0)
		error = width_formatting(c);
	if (error)
		free(c->value);
	return (error);
}

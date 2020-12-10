/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:22:19 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/10 13:54:00 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		normal_text(char **output, const char *str)
{
	size_t		i;
	char		*text;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	text = ft_substr(str, 0, i);
	if (!text)
		return (0);
	*output = ft_strjoin(*output, text);
	free(text);
	if (!output)
		return (0);
	return (i);
}

size_t		special_character(char **output, const char *str, va_list args)
{
	size_t		i;
	int			error;
	t_track		c;

	t_track_init(&c);
	i = flaghandler(&c, str, args);
	if (!i)
		return (0);
	error = value_converter(args, &c);
	if (error)
		return (0);
	error = value_formatter(&c);

	return (i);
}

char	*string_parser(const char *str, va_list args)
{
	char		*output;
	size_t		i;

	output = ft_calloc(1,1);
	if (!output)
		return (NULL);
	while (*str)
	{
		if (*str != '%')
			i = normal_text(&output, str);
		else
			i = special_character(&output, str, args);
		if (i == (size_t)0)
		{
			free(output);
			return (NULL);
		}
		str += i;
	}
	return (output);
}

void	ft_printf(const char *str, ...)
{
	va_list		args;
	char		*output;

	if (!str)
		return ;
	va_start(args, str);
	output = string_parser(str, args);
	va_end(args);
	ft_putstr_fd(output, 1);
	if (output)
		free(output);
}

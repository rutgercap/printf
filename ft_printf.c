/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:22:19 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/11 16:48:33 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		normal_text(char **output, const char *str)
{
	size_t		i;
	char		*normal_text;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	normal_text = ft_substr(str, 0, i);
	if (!normal_text)
		return (0);
	*output = ft_strjoin(*output, normal_text);
	free(normal_text);
	if (!output)
		return (0);
	return (i);
}

size_t		special_character(char **output, size_t *len,
			const char *str, va_list args)
{
	size_t		i;
	t_track		c;
	int			error;

	t_track_init(&c);
	i = flaghandler(&c, str, args);
	if (!i)
		return (0);
	error = value_converter(args, &c);
	if (error)
		return (0);
	error = value_formatter(&c);
	if (error)
		return (0);
	error = value_output_combiner(output, &c, len);
	if (error)
		return (0);
	return (i);
}

size_t		string_parser(char **output, const char *str, va_list args)
{
	size_t			i;
	size_t			len;

	*output = ft_calloc(1, 1);
	if (!*output)
		return (0);
	len = 0;
	while (*str)
	{
		if (*str != '%')
		{
			i = normal_text(output, str);
			len += i;
		}
		else
			i = special_character(output, &len, str, args);
		if (i == (size_t)0)
		{
			free(*output);
			return (0);
		}
		str += i;
	}
	return (len);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	char		*output;
	size_t		len;

	if (!str)
		return (-1);
	va_start(args, str);
	len = string_parser(&output, str, args);
	va_end(args);
	print_string(output, len);
	return ((int)len);
}

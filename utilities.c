/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 12:48:48 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/11 15:50:12 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	counter(unsigned long long n)
{
	int		i;

	i = 1;
	while (n / 16 != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

char		*ft_itoa_ptr(unsigned long long n)
{
	char	*ret;
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = counter(n) + 2;
	ret = malloc(sizeof(unsigned char) * len + 1);
	if (!ret)
		return (NULL);
	ret[0] = '0';
	ret[1] = 'x';
	ret[len] = '\0';
	while (len > 2)
	{
		len--;
		ret[len] = base[n % 16];
		n = n / 16;
	}
	return (ret);
}

int		value_output_combiner(char **output, t_track *c, size_t *len)
{
	char	*temp;
	
	temp = ft_strjoin(*output, c->value);
	if (!temp)
	{
		free(c->value);
		return (EXIT_FAILURE);
	}
	*len += ft_strlen(c->value);
	free(*output);
	free(c->value);
	*output = temp;
	return (EXIT_SUCCESS);
}

void		print_string(char *output, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		write(1, &output[i], 1);
		i++;
	}
}
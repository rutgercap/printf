/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer_printer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 12:06:10 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/10 12:34:05 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	counter(unsigned int n)
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
	len = counter(n);
	ret = malloc(sizeof(unsigned char) * len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (len)
	{
		len--;
		ret[len] = base[n % 16];
		n = n / 16;
	}
	return (ret);
}
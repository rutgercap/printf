/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/08 14:36:33 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/10 12:00:09 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(unsigned int n, int baselen)
{
	int		i;

	i = 1;
	while (n / baselen != 0)
	{
		i++;
		n = n / baselen;
	}
	return (i);
}

char		*ft_itoa_base(unsigned int n, char *base)
{
	char	*ret;
	int		len;
	int		baselen;

	baselen = ft_strlen(base);
	if (baselen == 0)
		return (NULL);
	len = counter(n, baselen);
	ret = malloc(sizeof(unsigned char) * len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (len)
	{
		len--;
		ret[len] = base[n % baselen];
		n = n / baselen;
	}
	return (ret);
}
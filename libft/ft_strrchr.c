/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:34:35 by rcappend      #+#    #+#                 */
/*   Updated: 2020/11/13 08:57:20 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	found = (char *)s + ft_strlen(s);
	while (TRUE)
	{
		if (*found == (char)c)
			return (found);
		if (found == s)
			break ;
		found--;
	}
	return (NULL);
}

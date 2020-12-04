/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:41:53 by rcappend      #+#    #+#                 */
/*   Updated: 2020/11/12 12:22:26 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	temp_dst = (unsigned char*)dst;
	temp_src = (unsigned char*)src;
	if (temp_dst == NULL && temp_src == NULL)
		return (NULL);
	while (n > 0)
	{
		*temp_dst = *temp_src;
		temp_src++;
		temp_dst++;
		n--;
	}
	return (dst);
}

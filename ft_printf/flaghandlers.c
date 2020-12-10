/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flaghandlers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 15:01:13 by rcappend      #+#    #+#                 */
/*   Updated: 2020/12/10 10:02:50 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	t_track_init(t_track *c)
{
	c->value = NULL;
	c->type = 0;
	c->lalign = FALSE;
	c->space = ' ';
	c->width = -1;
	c->prec = -1;
}

/*
**	Reads the width or precision flag.
*/
static int		wi_pr_reader(int *ret, const char *str, va_list args, int i)
{
	if (str[i] == '*')
	{
		*ret = va_arg(args, int);
		i++;
	}
	else if (ft_isdigit(str[i]))
	{
		*ret = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

static int		flag_reader(t_track *c, const char *str, int i)
{
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
		{
			c->lalign = TRUE;
			c->space = ' ';
		}
		else if (str[i] == '0' && c->lalign == FALSE)
			c->space = '0';
		i++;
	}
	return (i);
}

/*
**	Reads the flags, width and precision for the special character.
**	Finally, it returns (i) the amount of steps needed
**	to parse over all the flags. Or 0 in case of an error.
*/
int		flaghandler(t_track *c, const char *str, va_list args)
{
	int		i;
	char	*types;

	types = "cspdiuxX%";
	i = 1;
	i = flag_reader(c, str, i);
	i = wi_pr_reader(&c->width, str, args, i);
	if (str[i] == '.')
		i = wi_pr_reader(&c->prec, str, args, i + 1);
	if (ft_strchr(types, str[i]) == NULL)
		return (0);
	c->type = str[i];
	return (i + 1);
}

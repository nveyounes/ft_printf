/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:11:00 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/24 15:19:03 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_log_char(va_list *args)
{
	char	c;

	c = (unsigned char)va_arg(*args, int);
	return (write(1, &c, 1));
}

int	ft_log_str(va_list *args)
{
	char	*s;
	int		count;

	count = 0;
	s = va_arg(*args, char *);
	if (!s)
		return (ft_writer("(null)"));
	while (*s)
	{
		if (write(1, s, 1) == -1)
			return (-1);
		count++;
		s++;
	}
	return (count);
}

int	ft_log_percent(va_list *args)
{
	(void)args;
	return (write(1, "%", 1));
}

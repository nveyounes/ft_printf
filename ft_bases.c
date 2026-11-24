/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 21:44:56 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/24 15:21:26 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_small_x(va_list *args)
{
	int				result;
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	result = ft_all_in_one_base((unsigned long)n, "0123456789abcdef", 16);
	return (result);
}

int	ft_big_x(va_list *args)
{
	int				result;
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	result = ft_all_in_one_base((unsigned long)n, "0123456789ABCDEF", 16);
	return (result);
}

int	ft_u(va_list *args)
{
	int				result;
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	result = ft_all_in_one_base((unsigned long)n, "0123456789", 10);
	return (result);
}

int	ft_p(va_list *args)
{
	void	*p;
	int		result;

	p = va_arg(*args, void *);
	if (!p)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	result = ft_all_in_one_base((unsigned long)p, "0123456789abcdef", 16);
	if (result == -1)
		return (-1);
	return (result + 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_in_one_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 20:43:25 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/24 15:23:28 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_all_in_one_base(unsigned long n, const char *base, int base_number)
{
	int		count;
	char	buff[21];
	int		i;

	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	count = 0;
	while (n != 0)
	{
		buff[i] = base[n % base_number];
		i++;
		n /= base_number;
	}
	count = i;
	buff[i] = '\0';
	while (i-- > 0)
	{
		if (write(1, &buff[i], 1) == -1)
			return (-1);
	}
	return (count);
}

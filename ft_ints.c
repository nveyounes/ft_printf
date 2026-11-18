/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:07:46 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/18 19:32:31 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_writer(char *buff)
{
	int	i;
	int	verf;

	verf = 0;
	i = 0;
	while (buff[i])
	{
		verf = write(1, &buff[i], 1);
		if (verf == -1)
			return (-1);
		i++;
	}
	return (i);
}
static int	ft_count_helper(long n, int count, int *offset, char *buff)
{
	if (n == 0)
	{
		count++;
		return (count);
	}
	if (n <= -1)
	{
		n = -n;
		*offset = 1;
		buff[0] = '-';
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_log_i(va_list *args)
{
	long	n;
	int		count;
	char	buff[12];
	int		offset;
	int		total;
	int		count_backup;

	offset = 0;
	total = 0;
	count = 0;
	n = va_arg(*args, int);
	count = ft_count_helper(n, count, &offset, buff);
	if (n <= -1)
		n = -n;
	count_backup = count;
	while (count > offset)
	{
		buff[--count] = n % 10 + '0';
		n /= 10;
	}
	buff[count_backup] = '\0';
	total = ft_writer(buff);
	return (total);
}

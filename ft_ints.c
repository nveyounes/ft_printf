/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:07:46 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/24 16:11:50 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_filler(int count, int offset, char *buff, long n)
{
	int	count_backup;

	count_backup = count;
	while (count > offset)
	{
		buff[--count] = n % 10 + '0';
		n /= 10;
	}
	buff[count_backup] = '\0';
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

	offset = 0;
	total = 0;
	count = 0;
	n = va_arg(*args, int);
	count = ft_count_helper(n, count, &offset, buff);
	if (n <= -1)
		n = -n;
	ft_filler(count, offset, buff, n);
	total = ft_writer(buff);
	return (total);
}

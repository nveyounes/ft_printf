/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:01:58 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/18 21:20:34 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_table(t_fmt_fn *arr)
{
	ft_bzero(arr, 128 * sizeof(*arr));
	arr['c'] = ft_log_char;
	arr['s'] = ft_log_str;
	arr['%'] = ft_log_percent;
	arr['i'] = ft_log_i;
	arr['d'] = ft_log_i;
	arr['x'] = ft_x;
}

static int	ft_result_checker(t_fmt_fn *arr, int *i, char const *format, va_list *args)
{
	int	result;

	result = 0;
	if (format[*i + 1] == '\0')
		return (-1);
	if ((unsigned char)format[*i + 1] < 128 && arr[(unsigned char)format[*i + 1]] != NULL)
	{
		result = arr[(unsigned char)format[*i + 1]](args);
		*i += 2;
	}
	else
	{
		result = write(1, &format[*i], 1);
		(*i)++;
	}
	return (result);
}

static int	ft_checker(t_fmt_fn *arr, const char *format, va_list *args)
{
	int	i;
	int	total;
	int	result;

	result = 0;
	total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			result = ft_result_checker(arr, &i, format, args);
		else
		{
			result = write(1, &format[i], 1);
			i++;
		}
		if (result == -1)
			return (-1);
		total += result;
	}
	return (total);
}

int	ft_printf(char const *format, ...)
{
	va_list		args;
	t_fmt_fn	arr[128];
	int			check;

	ft_init_table(arr);
	va_start(args, format);
	check = ft_checker(arr, format, &args);
	va_end(args);
	if (check == -1)
		return (-1);
	return (check);
}
#include <stdio.h>

int	main(void)
{
	int	count_his;
	int count_mine;
	int n = -2147483648;
	int N = 1;
	
	// char *s = "nice";
	// close(1);

	count_mine = ft_printf("hello %s %i %d", "nice", n, N);
	
	printf("\n");
	count_his = printf("hello %s %i %d", "nice", n, N);


	 // dprintf(2, "count : %d\n", count);
	printf("\n");
	printf("count mine : %d\n", count_mine);
	printf("count his: %d\n", count_his);
}

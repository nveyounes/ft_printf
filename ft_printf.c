/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:01:58 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/17 21:17:08 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_table(t_fmt_fn *arr)
{
	ft_bzero(arr, 128 * sizeof(*arr));
	arr['c'] = ft_log_char;
	arr['s'] = ft_log_str;
	arr['%'] = ft_log_percent;
}
static int ft_result_checker(int result, int *total)
{
	if (result == -1)
		return (-1);
	return (*total =+ result);
	
}

static int	ft_checker(t_fmt_fn *arr, const char *format, va_list *args)
{
	int	result;
	int	i;
	int	total;

	total = 0;
	i = 0;
	result = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((unsigned char)format[i + 1] < 128 && arr[(unsigned char)format[i + 1]] != NULL)
			{ 
				result = arr[(unsigned char)format[i + 1]](args);
				i += 2;
			} 
		}
		if (format[i])
			return (total);
		result = write(1, &format[i], 1);
		ft_result_checker(result, &total);
		i++;
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
int main(){
	//char *s = "nice";
	int count = ft_printf("%c", '\0');
	printf("\n");
	printf("count : %d\n", count);
}

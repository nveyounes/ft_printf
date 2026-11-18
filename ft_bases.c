/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 21:44:56 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/18 22:24:25 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x(va_list *args)
{
    int result;
    unsigned int n;

    n = va_arg(*args, unsigned int);
    result = ft_all_in_one_base(n, "0123456789abcdef");
}

int	ft_X(va_list *args)
{
    int result;
    unsigned int n;

    n = va_arg(*args, unsigned int);
    result = ft_all_in_one_base(n, "0123456789ABCDEF");
}

int	ft_u(va_list *args)
{
    int result;
    unsigned int n;

    n = va_arg(*args, unsigned int);
    result = ft_all_in_one_base(n, "0123456789");
}

int	ft_u(va_list *args)
{
    void *p;
    int result;

    p = va_arg(*args, void *);
    result = ft_all_in_one_base(p, "0123456789abcdef");
}
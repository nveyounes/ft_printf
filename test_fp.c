/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:03:27 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/17 15:46:09 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <stdio.h>
#include "ft_printf.h"

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

void init(t_fmt_fn arr[128])
{
    ft_bzero(arr, 128 * sizeof(t_fmt_fn));
    arr['+'] = add;
    arr['-'] = sub;    
}
int calculate(char op, int a, int b)
{
    t_fmt_fn ops[128];
    init(ops);
    
    if ((unsigned char)op < 128 && ops[(unsigned char)op] != NULL)
    {
        return (ops[(unsigned char)op](a, b));
    }
    return (-1);
}

int main()
{
    printf("%d\n",calculate('+', 5, 5));
    printf("%d\n",calculate('-', 5, 5));
    printf("%d\n",calculate('/', 5, 5));
}
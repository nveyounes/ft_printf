/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:51:49 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/24 15:21:39 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./Libft/libft.h"
# include <stdarg.h>
# include <stddef.h>

typedef int	(*t_fmt_fn)(va_list *);
int			ft_writer(char *buff);
int			ft_log_char(va_list *args);
int			ft_log_str(va_list *args);
int			ft_log_percent(va_list *args);
int			ft_log_i(va_list *args);
void		init_table(t_fmt_fn arr[128]);
int			ft_printf(char const *format, ...);
int			ft_u(va_list *args);
int			ft_small_x(va_list *args);
int			ft_big_x(va_list *args);
int			ft_p(va_list *args);
int			ft_all_in_one_base(unsigned long n, const char *base,
				int base_number);

#endif
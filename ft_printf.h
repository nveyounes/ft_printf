/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:51:49 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/17 18:30:35 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./Libft/libft.h"
# include <stdarg.h>
# include <stddef.h>

typedef int	(*t_fmt_fn)(va_list *);
int			ft_log_char(va_list *args);
int			ft_log_str(va_list *args);
int			ft_log_percent(va_list *args);
void		init_table(t_fmt_fn arr[128]);
int			ft_printf(char const *format, ...);


#endif
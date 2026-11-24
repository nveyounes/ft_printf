/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarhat <yfarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 20:42:21 by yfarhat           #+#    #+#             */
/*   Updated: 2026/11/24 15:22:27 by yfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writer(char *buff)
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

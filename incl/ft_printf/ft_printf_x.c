/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:30:30 by alappas           #+#    #+#             */
/*   Updated: 2023/08/01 03:12:58 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_len_x(unsigned int v)

{
	int	len;

	len = 0;
	if (v < 0)
		len = 1;
	while (v != 0)
	{
		len++;
		v /= 16;
	}
	return (len);
}

int	ft_printf_x(unsigned int v)

{
	int	xlen;

	xlen = ft_len_x(v);
	if (v == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (v >= 16)
	{
		ft_printf_x(v / 16);
		ft_printf_x(v % 16);
	}
	else
	{
		if (v <= 9)
			ft_putchar_fd((v + '0'), 1);
		else
			ft_putchar_fd((v - 10 + 'a'), 1);
	}
	return (xlen);
}

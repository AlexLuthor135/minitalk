/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:30:30 by alappas           #+#    #+#             */
/*   Updated: 2023/08/01 03:13:01 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_len_x2(unsigned int v2)

{
	int	len;

	len = 0;
	if (v2 < 0)
		len = 1;
	while (v2 != 0)
	{
		len++;
		v2 /= 16;
	}
	return (len);
}

int	ft_printf_x2(unsigned int v2)

{
	int	xlen;

	xlen = ft_len_x2(v2);
	if (v2 == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (v2 >= 16)
	{
		ft_printf_x2(v2 / 16);
		ft_printf_x2(v2 % 16);
	}
	else
	{
		if (v2 <= 9)
			ft_putchar_fd((v2 + '0'), 1);
		else
			ft_putchar_fd((v2 - 10 + 'A'), 1);
	}
	return (xlen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:32:42 by alappas           #+#    #+#             */
/*   Updated: 2023/08/01 03:12:35 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_len_p(uintptr_t v)

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

void	ft_printf_hex(unsigned long long v)

{
	if (v == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	if (v >= 16)
	{
		ft_printf_hex(v / 16);
		ft_printf_hex(v % 16);
	}
	else
	{
		if (v <= 9)
			ft_putchar_fd((v + '0'), 1);
		else
			ft_putchar_fd((v - 10 + 'a'), 1);
	}
}

int	ft_printf_p(unsigned long long ptr)

{
	int	len;

	len = 0;
	len += write (1, "0x", 2);
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	else
	{
		ft_printf_hex(ptr);
		len += ft_len_p(ptr);
	}
	return (len);
}

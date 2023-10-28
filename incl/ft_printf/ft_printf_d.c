/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:50:35 by alappas           #+#    #+#             */
/*   Updated: 2023/08/01 03:12:31 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_count_d(int n)

{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_printf_d(int n)

{
	int	dlen;

	dlen = ft_count_d(n);
	if (n == -2147483648)
	{
		ft_putchar_fd ('-', 1);
		ft_putchar_fd ('2', 1);
		ft_printf_d (147483648);
	}
	else if (n < 0)
	{
		ft_putchar_fd ('-', 1);
		n = -n;
		ft_printf_d (n);
	}
	else if (n > 9)
	{
		ft_printf_d (n / 10);
		ft_printf_d (n % 10);
	}
	else
		ft_putchar_fd (n + 48, 1);
	return (dlen);
}

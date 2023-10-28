/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:13:01 by alappas           #+#    #+#             */
/*   Updated: 2023/08/01 03:12:55 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_count_u(unsigned int n)

{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_printf_undec(unsigned int n)

{
	if (n >= 10)
	{
		ft_printf_undec ((n / 10));
		ft_printf_undec (n % 10);
	}
	else if (n < 10)
		ft_putchar_fd (n + 48, 1);
	return (ft_count_u(n));
}

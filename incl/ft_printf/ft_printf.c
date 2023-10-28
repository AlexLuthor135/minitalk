/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:03:34 by alappas           #+#    #+#             */
/*   Updated: 2023/08/01 03:13:04 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_format(va_list args, char f)

{
	int	value;

	value = 0;
	if (f == 'c')
		value += ft_printf_char(va_arg(args, int));
	else if (f == 's')
		value += ft_printf_s(va_arg(args, char *));
	else if (f == 'p')
		value += ft_printf_p(va_arg(args, unsigned long long));
	else if (f == 'd' || f == 'i')
		value += ft_printf_d(va_arg(args, int));
	else if (f == 'u')
		value += ft_printf_undec(va_arg(args, unsigned int));
	else if (f == 'x')
		value += ft_printf_x(va_arg(args, unsigned int));
	else if (f == 'X')
		value += ft_printf_x2(va_arg(args, unsigned int));
	else if (f == '%')
		value += ft_printf_prc();
	return (value);
}

int	ft_printf(const char *s, ...)

{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_format(args, s[i + 1]);
			i++;
		}
		else
			len += ft_printf_char(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}

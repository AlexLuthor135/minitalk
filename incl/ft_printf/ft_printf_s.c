/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:49:26 by alappas           #+#    #+#             */
/*   Updated: 2023/08/01 03:12:51 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_printf_s(char *string)

{
	int	len;
	int	index;

	index = 0;
	if (!string)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(string);
	while (string[index] != '\0')
	{
		write(1, &string[index], 1);
		index++;
	}
	return (len);
}

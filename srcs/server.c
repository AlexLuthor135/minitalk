/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:06:59 by alappas           #+#    #+#             */
/*   Updated: 2023/09/30 22:15:15 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"

void	ft_signal(int bit)

{
	if (bit == SIGUSR1)
		ft_fill_char(1);
	if (bit == SIGUSR2)
		ft_fill_char(0);
}

void	ft_fill_char(int bit)

{
	static int	i;
	static char	symbol;

	if (i < 8)
	{
		symbol = symbol + (bit << i);
		i++;
	}
	if (i == 8)
	{
		ft_printf("%c", symbol);
		i = 0;
		symbol = 0;
	}
}

int	main(void)

{
	int	pid;

	pid = getpid();
	ft_printf("%i\n", pid);
	signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);
	write(1, "\n", 1);
	while (1)
		sleep(1);
	return (0);
}

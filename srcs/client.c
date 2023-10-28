/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:20:22 by alappas           #+#    #+#             */
/*   Updated: 2023/10/01 18:03:20 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"

void	send_symbol(int pid, char c)

{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 1) == 1)
		{
			kill(pid, SIGUSR1);
			usleep(50);
		}
		if ((c & 1) == 0)
		{
			kill(pid, SIGUSR2);
			usleep(50);
		}
		c = c >> 1;
		i++;
	}
}

int	main(int argc, char **argv)

{
	int		pid;
	char	*s;
	int		i;

	if (argc != 3)
	{
		ft_printf("Wrong amount of arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	s = argv[2];
	i = 0;
	if (kill(pid, 0) != 0)
	{
		ft_printf("Signal was not sent\n");
		return (0);
	}
	while (s[i])
	{
		send_symbol(pid, s[i]);
		i++;
	}
	return (0);
}

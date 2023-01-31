/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahamoun <lahamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:55:28 by lahamoun          #+#    #+#             */
/*   Updated: 2023/01/30 19:24:22 by lahamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	ft_convert(int pid, unsigned char c)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (i < 8)
	{
		m = c % 2;
		if (m != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		c = c / 2;
		usleep(300);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	i = 0 ;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write(1, "Enter the correct PID \n", 23);
			exit(1);
		}
		while (av[2][i])
		{
			ft_convert(pid, (unsigned char)av[2][i]);
			i++;
		}
		ft_convert(pid, av[2][i]);
		ft_convert(pid, '\n');
	}
	else
		write(1, "Wrong server PID or message, try again\n", 39);
	return (0);
}

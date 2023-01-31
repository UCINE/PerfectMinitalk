/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahamoun <lahamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:42:14 by lahamoun          #+#    #+#             */
/*   Updated: 2023/01/30 19:42:25 by lahamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_convert(int pid, unsigned char c)
{
	int	i;
	int	mod;

	i = 0;
	mod = 0;
	while (i < 8)
	{
		mod = c % 2;
		if (mod != 0)
		{
			kill(pid, SIGUSR1);
			pause();
		}
		else
		{
			kill(pid, SIGUSR2);
			pause();
		}
		i++;
		c = c / 2;
		usleep(50);
	}
}

void	ft_handler(int signal)
{
	(void) signal;
	write(1, "signal is received\n", 19);
}

void	send(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_convert(pid, (unsigned char)str[i]);
		i++;
	}
	ft_convert(pid, '\n');
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write(1, "Enter the correct PID \n", 23);
			exit(1);
		}
		signal(SIGUSR1, ft_handler);
		send(pid, av[2]);
	}
	else
		write(1, "Wrong server PID or message, try again\n", 39);
	return (0);
}

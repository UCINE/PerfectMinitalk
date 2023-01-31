/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahamoun <lahamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:34:37 by lahamoun          #+#    #+#             */
/*   Updated: 2023/01/30 19:34:37 by lahamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static	void	handler(int signal, siginfo_t *info, void *context)
{
	static int	c;
	static int	i;
	static int	pow;

	(void) context;
	if (i == 0)
		pow = 1;
	if (signal == SIGUSR1)
		c += pow ;
	pow *= 2;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	usleep(500);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	write(1, "server PID ", 11);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}

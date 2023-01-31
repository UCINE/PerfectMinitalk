/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahamoun <lahamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:55:31 by lahamoun          #+#    #+#             */
/*   Updated: 2023/01/30 19:25:29 by lahamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	handler(int signal)
{
	static int	character;
	static int	i;
	static int	p;

	if (i == 0)
		p = 1;
	if (signal == SIGUSR1)
		character += p ;
	p *= 2;
	i++;
	if (i == 8)
	{
		write(1, &character, 1);
		character = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "server PID ", 11);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}

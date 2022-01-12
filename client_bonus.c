/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:40:31 by msainton          #+#    #+#             */
/*   Updated: 2022/01/12 18:08:19 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>

void	send_byte(char c, int pid)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (1 & (c >> i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(50);
	}
}

void	send_str(char *str, int pid)
{
	int	a;

	a = 0;
	while (str[a])
	{
		send_byte(str[a], pid);
		a++;
	}
	send_byte(0, pid);
}

void	message_sent(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("message receipt by the server\n");
}

int	ft_num(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		if (str[a] < 48 || str[a] > 57)
			return (1);
		a++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	yo;

	sigemptyset(&yo.sa_mask);
	yo.sa_flags = 0;
	yo.sa_handler = message_sent;
	sigaction(SIGUSR1, &yo, NULL);
	if (argc == 3 && ft_num(argv[1]) == 0)
	{
		pid = ft_atoi(argv[1]);
		send_str(argv[2], pid);
	}
	else
		ft_putstr_fd("Error: usage: ./client <pid> <mesage>\n", 2);
	return (0);
}

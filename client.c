/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:55:20 by msainton          #+#    #+#             */
/*   Updated: 2021/12/30 11:44:59 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	send_byte(char c, int pid)
{
	int		i;

	i = 8;
	while (i > 0)
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
		printf("%c\n", str[a]);
		a++;
	}
	send_byte(0, pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	send_str(argv[2], pid);
	return (0);
}

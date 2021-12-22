/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:55:20 by msainton          #+#    #+#             */
/*   Updated: 2021/12/22 16:26:59 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
}

int	main(int argc, char **argv)
{
	int	pid;
	
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	send_str(argv[2], pid);
}
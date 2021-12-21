/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:55:11 by msainton          #+#    #+#             */
/*   Updated: 2021/12/21 12:08:42 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_bytes(int sig)
{
	char	*bytes;
	int		i;

	if (i < 8)
	{
		if (sig == SIGUSR1)
			*bytes |= (1 << i++);
		else (sig == SIGUSR2)
			*bytes |= (0 << i++);
			
		i++;
	}
}

void	send_msg(int sig, siginfo_t *info, void *ucontext)
{		
}

int	main()
{
	int 				pid;
	struct sigaction	yo;

	pid = getpid();

	yo.sa_sigaction = send_msg;
	yo.sa_flags = SA_SIGINFO;
	sigemptyset(&yo.sa_mask);
	sigaction(SIGUSR1, &yo, NULL);
	sigaction(SIGUSR2, &yo, NULL);
	printf("%d\n", pid);
	while (1)
	{
		sleep(5);
	}
}
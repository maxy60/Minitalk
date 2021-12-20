/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:55:11 by msainton          #+#    #+#             */
/*   Updated: 2021/12/20 16:10:52 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_bytes(int sig)
{
	if (sig == SIGUSR1)
		
	else (sig == SIGUSR2)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:55:11 by msainton          #+#    #+#             */
/*   Updated: 2021/12/11 17:12:03 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(char **argv)
{
	 char	*s;
	 
	 s = argv[2];
}

int	main()
{
	int 				pid;
	struct sigaction	yo;

	pid = getpid();

//	yo.sa_sigaction = send_msg;
	yo.sa_flags = SA_SIGINFO;
	sigemptyset(&yo.sa_mask);
	sigaction(SIGUSR1, &yo, NULL);
	printf("%d\n", pid);
	while (1)
	{
		sleep(5);
	}
}
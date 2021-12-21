/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:55:11 by msainton          #+#    #+#             */
/*   Updated: 2021/12/21 16:41:28 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void		ft_bytes(int sig)
{
	char	*bytes;
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (sig == SIGUSR1)
			*bytes = 1 & (*bytes >> i);
		else if (sig == SIGUSR2)
			*bytes = 0 & (*bytes >> i);
		i--;
	}
}

//char	*my_str(int sig)
//{
//	while ()
//}

void	send_msg(int sig, siginfo_t *info, void *ucontext)
{
	ft_bytes(sig);
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
		sleep(1000);
	}
}
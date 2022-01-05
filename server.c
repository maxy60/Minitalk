/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:55:11 by msainton          #+#    #+#             */
/*   Updated: 2021/12/30 10:53:34 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

char    *ft_strcjoin(char *str, char c)
{
        char    *dest;
        size_t  a;

        a = 0;
        dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
        if (!dest)
                return (NULL);
        while (str[a])
        {
                dest[a] = str[a];
                a++;
        }
		a++;
		dest[a] = c;
        dest[a + 1] = '\0';
		if (str)
			free(str);
        return (dest);
}

int	ft_bytes(char bytes, int sig)
{
	static int		i;

	i = 0;
	if (i == 8)
	{
		bytes = 0;
		i = 0;
	}	
	//while (i >= 0)
	if (i < 8)
	{
		if (sig == SIGUSR1)
			bytes |= (1 << i++);
		else if (sig == SIGUSR2)
			bytes |= (0 << i++);
		//i--;
	}
	return (i);
}

void	send_msg(int sig, siginfo_t *info, void *ucontext)
{
	static char	*s;
	static char c;
	int		i;

	c = 0;
	(void)ucontext;
	i = ft_bytes(c, sig);
	if (i == 8 && c)
		s = ft_strcjoin(s, c);
	if (i == 8 && !c)
	{
		ft_putnbr(info->si_pid);
		ft_putstr(s);
	}
	printf("test");
}

int	main()
{
	int 				pid;
	struct sigaction	yo;

	pid = getpid();

	yo.sa_flags = SA_SIGINFO;
	sigemptyset(&yo.sa_mask);
	yo.sa_sigaction = send_msg;
	sigaction(SIGUSR1, &yo, NULL);
	sigaction(SIGUSR2, &yo, NULL);
	printf("%d\n", pid);
	while (1)
	{
		pause();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:55:11 by msainton          #+#    #+#             */
/*   Updated: 2021/12/22 16:23:10 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
        return (dest);
}

char	ft_bytes(int sig)
{
	int		i;
	char	bytes;

	i = 7;
	bytes = 0;
	while (i >= 0)
	{
		if (sig == SIGUSR1)
			bytes |= (1 << i);
		else if (sig == SIGUSR2)
			bytes |= (0 << i);
		i--;
	}
	return (bytes);
}

char	*my_str(int sig)
{
	char	*str;
	int		i;

	*str = ft_bytes(sig);
	while (*str != 0)
		str = ft_strcjoin(str, ft_bytes(sig));
	return (str);
}

void	send_msg(int sig, siginfo_t *info, void *ucontext)
{
	ft_putstr(my_str(sig));
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
		sleep(100);
	}
}
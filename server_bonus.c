/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:41:56 by msainton          #+#    #+#             */
/*   Updated: 2022/01/11 18:11:09 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

char	*ft_strcjoin(char *str, char c)
{
	char	*dest;
	size_t	a;

	a = 0;
	if (str)
	{
		dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
		while (str[a])
		{
			dest[a] = str[a];
			a++;
		}
		a++;
	}
	else
		dest = (char *)malloc(sizeof(char) * 2);
	if (!dest)
		return (NULL);
	dest[a] = c;
	dest[a + 1] = '\0';
	if (str)
		free(str);
	return (dest);
}

void	send_msg(int sig, siginfo_t *info, void *context)
{
	static int	pos;
	static int	bit;
	static char	*str;

	(void)info;
	(void)context;
	if (!str)
		str = NULL;
	if (sig == SIGUSR1)
		bit += 1 << (7 - pos);
	pos++;
	if (pos == 8)
	{
		if (bit == '\0')
			ft_putchar('\n');
		str = ft_strcjoin(str, (char)bit);
		pos = 0;
		bit = 0;
	}
	else
	{
		ft_putstr(str);
		free(str);
		str = NULL;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	yo;

	if (ac == 1)
	{
		pid = getpid();
		yo.sa_flags = SA_SIGINFO;
		sigemptyset(&yo.sa_mask);
		yo.sa_sigaction = send_msg;
		sigaction(SIGUSR1, &yo, NULL);
		sigaction(SIGUSR2, &yo, NULL);
		ft_putstr("pid: ");
		ft_putnbr(pid);
		ft_putchar('\n');
		while (1)
			pause();
		return (EXIT_SUCCESS);
	}
	else
		ft_putstr_fd("Error: server dont need arg", 2);
}

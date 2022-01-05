/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:21:57 by msainton          #+#    #+#             */
/*   Updated: 2021/12/29 16:37:01 by maxime           ###   ########.fr       */
/*                                                                            */ 
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include "./libft/libft.h"

char	*ft_strcjoin(char *str, char c);

int		ft_byte(char byte, int signal);
void	send_msg(int signal, siginfo_t *info, void *context);

void	send_byte(char c, int pid);
void	send_str(char *str, int pid);

#endif

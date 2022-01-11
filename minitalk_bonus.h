/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:42:15 by msainton          #+#    #+#             */
/*   Updated: 2022/01/11 17:44:50 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include "./libft/libft.h"

char	*ft_strcjoin(char *str, char c);

int		ft_byte(char byte, int signal);
void	send_msg(int sig, siginfo_t *info, void *context);

void	send_byte(char c, int pid);
void	send_str(char *str, int pid);

#endif
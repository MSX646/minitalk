/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:54:35 by kezekiel          #+#    #+#             */
/*   Updated: 2021/11/22 14:55:48 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_chr
{
	int	bit;
	int	chr;
}	t_chr;

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	send_sig(int pid, int signum);
int		ft_atoi(const char *str);

#endif

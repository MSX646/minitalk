/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:53:05 by kezekiel          #+#    #+#             */
/*   Updated: 2021/11/22 14:54:27 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_chr	g_chr;

static void	server_handler(int sig, siginfo_t *siginfo, void *oldact)
{
	(void)oldact;
	g_chr.chr |= (sig == SIGUSR2);
	if (++g_chr.bit == 8)
	{
		g_chr.bit = 0;
		if (!g_chr.chr)
		{
			send_sig(siginfo->si_pid, SIGUSR2);
			return ;
		}
		ft_putchar(g_chr.chr);
		g_chr.chr = 0;
		send_sig(siginfo->si_pid, SIGUSR1);
	}
	else
		g_chr.chr <<= 1;
}

int	main(void)
{
	struct sigaction	sig;

	g_chr.bit = 0;
	g_chr.chr = 0;
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigemptyset(&sig.sa_mask);
	sig.sa_sigaction = server_handler;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, 0) == -1 || sigaction(SIGUSR2, &sig, 0) == -1)
	{
		write(2, "Sigaction error\n", 16);
		exit(1);
	}
	while (1)
		pause();
	return (0);
}

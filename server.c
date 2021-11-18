#include "minitalk.h"

static void	server_handler(int sig, siginfo_t *siginfo, void *oldact)
{
	static int				i = 0;
    static unsigned char	c = 0;

	(void)oldact;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			send_sig(siginfo->si_pid, SIGUSR2);
			return ;
		}
		ft_putchar(c);
		c = 0;
		send_sig(siginfo->si_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sig;

	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sig.sa_sigaction = server_handler;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, 0) == -1 ||
	    sigaction(SIGUSR2, &sig, 0) == -1)
    {
      write(2, "Sigaction error\n", 16);
      exit(1);
    }
	while (1)
		pause();
	return (0);
}

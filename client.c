#include "minitalk.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	client_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_putstr("Signal received\n");
		exit(0);
	}
}

static void	sender(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				send_sig(pid, SIGUSR2);
			else
				send_sig(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		send_sig(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	if (argc != 3 || !argv[2] || !ft_isdigit(argv[1][0]))
	{
      write(2, "Usage: <PID> <MSG>\n", 19);
      exit(1);
    }
    sig.sa_flags = SA_SIGINFO;
	//sigemptyset(&sig.sa_mask);
    sig.sa_handler = client_handler;
	if (sigaction(SIGUSR1, &sig, 0) == -1||
	    sigaction(SIGUSR2, &sig, 0) == -1)
    {
      write(2, "Sigaction error\n", 16);
      exit(1);
    }
	sender(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void    ft_putchar(char c);
void    ft_putnbr(int n);
void    ft_putstr(char *str);
void    send_sig(int pid, int signum);
int     ft_atoi(const char *str);

#endif

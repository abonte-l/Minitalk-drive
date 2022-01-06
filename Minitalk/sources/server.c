/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:58:25 by abonte-l          #+#    #+#             */
/*   Updated: 2022/01/06 14:08:21 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void   	receive_and_print(int signum, siginfo_t *siginfo, void *unused)
{
	static int  ascii = 0;
	static int  power = 0;

	(void)siginfo;
	(void)unused;
	if (signum == SIGUSR1)
		ascii += (128 >> power);
	power += 1;
	if (power < 8)
		return;
	ft_putchar(ascii);
	power = 0;
	ascii = 0;
}

void	checker_arg_pid(int pid, int ac)
{
	if (ac != 1)
	{
		ft_putstr(ERROR_ARG_SERV);
		exit(EXIT_FAILURE);
	}
	
	if (pid <= 0)
	{
		ft_putstr(ERROR_PID);
		exit(EXIT_FAILURE);
	}
	ft_putstr(PID_SUCCESS);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	struct sigaction	sa;
	int	pid;

	(void)av;
	pid = getpid();
	checker_arg_pid(pid, ac);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_and_print;
	if ((sigaction(SIGUSR1, &sa, 0)) == -1)
		ft_putstr("Error sigaction\n");
	if ((sigaction(SIGUSR2, &sa, 0)) == -1)
		ft_putstr("Error sigaction\n");
	while (1)
		sleep(5);
	return (0);
}
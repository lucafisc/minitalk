#include "../includes/minitalk.h"

void	client_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Server received message!\n");
	}
	else
		ft_printf("Something bad happened\n");
}	

void send_msg(int pid, char c)
{
	int x;
	x = 1;
	while (x <= 128)
	{
		if (c & x)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		x = x << 1;
	}
}

void	send_pid(int pid)
{
	int	*binary;
	int	i;

	i = 0;
	binary = int_to_binary(getpid());
	while (i < 32)
	{
		if (binary[i] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int i;
	int pid;
	struct sigaction	act;

	act.sa_handler = &client_handler;

	if (argc != 3)
	{
		ft_printf(BRED "Invalid arguments\n" COLOR_RESET);
		ft_printf(BYEL "Try &>%s <PID> <\"message\">\n", argv[0], COLOR_RESET);
		return (1);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	ft_printf("Client PID: %d\n", getpid());
	ft_printf("Server PID: %d\n", pid);
	send_pid(pid);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	while (argv[2][i])
	{
		send_msg(pid, argv[2][i]);
		i++;
	}
	while (1)
	{
		pause();
	}
}

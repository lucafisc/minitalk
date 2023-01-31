#include "../includes/minitalk.h"

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
	int	p;
	ft_printf("PID: %d\n", pid);
	binary = int_to_binary(pid);
	p = binary_to_int(binary);
	ft_printf("Converted back: %d", p);
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	int i;
	int pid;

	if (argc != 3)
	{
		ft_printf(BRED "Invalid arguments\n" COLOR_RESET);
		ft_printf(BYEL "Try &>%s <PID> <\"message\">\n", argv[0], COLOR_RESET);
		return (1);
	}
	i = 0;
	send_pid(getpid());
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_msg(pid, argv[2][i]);
		i++;
	}
}

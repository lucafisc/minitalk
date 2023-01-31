#include "../includes/minitalk.h"

t_status status;

void	get_msg(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (00000001<< bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill(status.client_pid, SIGUSR1);
	}
}

void	get_pid(int signal)
{
	static int array[32];
	static int i;

	if (i < 32)
	{
		if (signal == SIGUSR1)
			array[i] = 1;
		else
			array[i] = 0;
		i++;
	}
	if (i == 32)
	{
		status.client_pid = binary_to_int(array);
		status.has_pid = true;
		ft_printf("%d", status.client_pid);
	}
}

void	handler(int signal)
{
	if (!status.has_pid)
	{
		get_pid(signal);
	}
	else
		get_msg(signal);
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;

	status.has_pid = false;
	status.client_pid = 0;
	ft_bzero(&act, sizeof(act));
	act.sa_handler = &handler;

	if (argc != 1)
	{
		ft_printf(BRED "Error\n" COLOR_RESET);
		ft_printf(BYEL "Try $>%s\n", argv[0], COLOR_RESET);
		return (1);
	}
	print_pid(getpid());
	while (1)
	{
		sigaction(SIGUSR2, &act, NULL);
		sigaction(SIGUSR1, &act, NULL);
		pause();
	}
	return 0;
}

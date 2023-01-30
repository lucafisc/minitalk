#include "../includes/minitalk.h"

void get_msg(int i)
{

}

int	main(int argc, char *argv[])
{
	int pid;

	if (argc != 1)
	{
		ft_printf(BRED "Error\n" COLOR_RESET);
		ft_printf(BYEL "Try $>%s\n", argv[0], COLOR_RESET);
		return (1);
	}
	pid = getpid();
	print_pid(pid);

	while (1)
	{
		signal(SIGUSR2, get_msg);
		signal(SIGUSR1, get_msg);
		pause();
	}
	return 0;
}

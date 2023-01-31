#include "../includes/minitalk.h"

void	init_status(t_status stat)
{
	stat.has_pid = false;
	stat.client_pid = NULL;
}

int binary_to_int(int binary[])
{
    int n = 0;
    int i = 0;
    int power = 1;
    while (i < 32)
    {
        n += binary[i] * power;
        power *= 2;
        i++;
    }
    return n;
}

int *int_to_binary(int n)
{
	int *binary;
	int i = 0;
	binary = ft_calloc(32, sizeof(int));
	ft_memset(binary, 0, sizeof(binary));
	while (n > 0)
	{
		binary[i] = n % 2;
		n = n / 2;
		i++;
	}
	return (binary);
}

void print_pid(int pid)
{
	ft_printf(BMAG "\n            _       _   _        _ _    \n" COLOR_RESET);
	ft_printf(BMAG "           (_)     (_) | |      | | |   \n" COLOR_RESET);
	ft_printf(BMAG "  _ __ ___  _ _ __  _  | |_ __ _| | | __\n" COLOR_RESET);
	ft_printf(BMAG " | '_ ` _ \\| | '_ \\| | | __/ _` | | |/ /\n" COLOR_RESET);
	ft_printf(BMAG " | | | | | | | | | | | | || (_| | |   < \n" COLOR_RESET);
	ft_printf(BMAG " |_| |_| |_|_|_| |_|_|  \\__\\__,_|_|_|\\_\\\n" COLOR_RESET);
	ft_printf(BMAG "\n               ");
	ft_printf(HMAG " PID = %d ", pid, COLOR_RESET);
	ft_printf(COLOR_RESET "\n\n");
}

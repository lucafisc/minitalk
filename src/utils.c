#include "../includes/minitalk.h"

void print_pid(int pid)
{
	ft_printf(BMAG "\n            _       _   _        _ _    \n" COLOR_RESET);
	ft_printf(BMAG "           (_)     (_) | |      | | |   \n" COLOR_RESET);
	ft_printf(BMAG "  _ __ ___  _ _ __  _  | |_ __ _| | | __\n" COLOR_RESET);
	ft_printf(BMAG " | '_ ` _ \\| | '_ \\| | | __/ _` | | |/ /\n" COLOR_RESET);
	ft_printf(BMAG " | | | | | | | | | | | | || (_| | |   < \n" COLOR_RESET);
	ft_printf(BMAG " |_| |_| |_|_|_| |_|_|  \\__\\__,_|_|_|\\_\\\n" COLOR_RESET);
	ft_printf(BMAG "\n               ");
	ft_printf(MAGB " PID = %d ", pid, COLOR_RESET);
	ft_printf(COLOR_RESET "\n\n");
}

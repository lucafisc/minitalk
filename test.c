/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:28:10 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/29 15:51:10 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void	handler(int num)
{
	write(STDOUT_FILENO, "Hello\n", 6);
}

int	main(int argc, char* argv[])
{
	signal(SIGINT, handler);
	signal(SIGTERM, handler);
	while (1)
	{
		printf("my process id: %d\n", getpid());
		sleep(1);
	}
	
}
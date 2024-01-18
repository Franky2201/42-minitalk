/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:02:37 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/18 17:20:33 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_intercept_signal(int signal)
{
	static size_t	bit_shift;
	static char		c;

	if (signal == SIGUSR1)
		c |= (1 << bit_shift);
	if (signal == SIGUSR1 || signal == SIGUSR2)
		bit_shift++;
	if (bit_shift > 7)
	{
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
		bit_shift = 0;
		c = '\0';
	}
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	pid = getpid();
	ft_printf("Server PID: %i\n", pid);
	ft_bzero(&action, sizeof(action));
	action.sa_handler = ft_intercept_signal;
	if (sigaction(SIGUSR1, &action, NULL) != 0)
	{
		ft_printf("ERROR - COULD NOT ASSIGN ACTION TO SIGNAL\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &action, NULL) != 0)
	{
		ft_printf("ERROR - COULD NOT ASSIGN ACTION TO SIGNAL\n");
		exit(EXIT_FAILURE);
	}
	while (true)
	{
		usleep(200);
	}
}

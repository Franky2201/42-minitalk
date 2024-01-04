/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:02:48 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/05 00:47:20 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_send_char_to_server(pid_t pid, char c)
{
	size_t	bit_shift;

	bit_shift = 0;
	while (bit_shift < 8)
	{
		if ((c & (1 << bit_shift)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_shift++;
		usleep(50);
	}
}

void	ft_check_args(int ac, char **av, int pid)
{
	size_t	i;

	if (ac != 3)
	{
		ft_printf("INVALID NUMBER OF ARGUMENTS\n");
		ft_printf("usage : ./client.c <server_PID> <string_to_send>\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (ft_isdigit(av[1][i]) == 1)
		i++;
	if (av[1][i] != '\0' || pid < 1 || pid >= INT_MAX)
	{
		ft_printf("INVALID PID\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	size_t	i;
	int		pid;

	pid = ft_atoi(av[1]);
	ft_check_args(ac, av, pid);
	i = 0;
	while (av[2][i] != '\0')
	{
		ft_send_char_to_server((pid_t)pid, av[2][i]);
		i++;
	}
	ft_send_char_to_server((pid_t)pid, '\0');
}

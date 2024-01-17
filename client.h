/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:26:27 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/17 15:38:23 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include "libft/libft.h"

int		main(int ac, char **av);
void	ft_check_args(int ac, char **av, int *pid);
void	ft_send_char_to_server(pid_t pid, char c);

#endif

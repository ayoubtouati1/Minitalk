/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:48:47 by atouati           #+#    #+#             */
/*   Updated: 2022/06/12 01:48:19 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler(int sig)
{
	static int	i;
	static char	currunt_char;

	if (sig == SIGUSR2)
		currunt_char = currunt_char | 1 << i;
	i++;
	if (i == 8)
	{
		ft_putchar_fd(currunt_char, 1);
		currunt_char = 0;
		i = 0;
	}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	ft_putstr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}

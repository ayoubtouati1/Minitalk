/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:45:29 by atouati           #+#    #+#             */
/*   Updated: 2022/06/12 01:00:24 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	send_str(int pid, char *str_to_send)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str_to_send[j])
	{
		while (i < 8)
		{
			if (str_to_send[j] & 1 << i)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	get_pid(char *str_pid)
{
	int	pid;

	pid = atoi(str_pid);
	return (pid);
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc == 3)
	{
		pid = get_pid(argv[1]);
		if (pid <= 0 || argv[2] == '\0')
		{
			exit(1);
		}
		send_str(pid, argv[2]);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:03:12 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/23 13:25:36 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// Flib prototypes:
int			fl_strtoi(char *str, int *num);

/*Main function for client.*/
int	main(int argc, char **argv)
{
	pid_t				pid_server;

	if (argc != 3)
		fl_pexit("Wrong arguments. Enter \"./client [server_pid] [message]\"");
	if (fl_strtoi(argv[1], &pid_server) == -1)
		fl_pexit("Invalid PID");
	while (*argv[2])
	{
		f_send_char(pid_server, *argv[2]);
		argv[2]++;
	}
	f_send_char(pid_server, '\0');
	return (0);
}

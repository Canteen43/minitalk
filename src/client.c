/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:03:12 by kweihman          #+#    #+#             */
/*   Updated: 2024/09/17 11:03:12 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	f_strtoi(char *str, int *num);

/*Main function for client.*/
int	main(int argc, char **argv)
{
	pid_t	pid_server;

	if (argc != 3)
		f_pexit("Wrong arguments. Enter \"./client [server_pid] [message]\"");
	if (f_strtoi(argv[1], &pid_server) == -1)
		f_pexit("Invalid PID");
	while (*argv[2])
	{
		f_send_char(pid_server, *argv[2]);
		argv[2]++;
	}
	f_send_char(pid_server, '\0');
	return (0);
}

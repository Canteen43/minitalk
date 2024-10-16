/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:03:12 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/16 11:23:48 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int			f_strtoi(char *str, int *num);
static void	handler(int signum);

/*Main function for client.*/
int	main(int argc, char **argv)
{
	pid_t				pid_server;
	struct sigaction	sa;

	sa.sa_handler = handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		f_pexit("sigemptyset failed");
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		f_pexit("sigaction 1 failed");
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
	pause();
	return (0);
}

static void	handler(int signum)
{
	if (signum == SIGUSR1)
		f_miniprint("Server sent confirmation signal\n");
}

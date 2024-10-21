/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:03:12 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/21 15:51:10 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int			fl_strtoi(char *str, int *num);
static void	handler(int signum);

/*Main function for client.*/
int	main(int argc, char **argv)
{
	pid_t				pid_server;
	struct sigaction	sa;

	sa.sa_handler = handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		fl_pexit("sigemptyset failed");
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		fl_pexit("sigaction 1 failed");
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
	pause();
	return (0);
}

static void	handler(int signum)
{
	if (signum == SIGUSR1)
		fl_miniprint("Server sent confirmation signal\n");
}

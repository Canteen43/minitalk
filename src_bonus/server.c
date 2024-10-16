/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:17:39 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/16 11:27:10 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

char	g_char;
pid_t	g_pid_client;

/*Main function for server.*/
int	main(void)
{
	pid_t	pid_server;
	t_alc	arr;

	pid_server = getpid();
	f_miniprint("Server PID: %d\n", pid_server);
	while (1)
	{
		if (f_alc_init(&arr, ARR_CAP) == -1)
			f_pexit("Error: array malloc failed\n");
		g_char = 1;
		while (g_char != '\0')
		{
			f_receive_char();
			if (f_alc_add(&arr, g_char) == -1)
			{
				free(arr.head);
				f_pexit("Error: adding element failed\n");
			}
		}
		usleep(200);
		if (kill(g_pid_client, SIGUSR1) == -1)
			f_pexit("Error: sending confirmation failed\n");
		f_miniprint("Received: |%s|\n", arr.head);
		free(arr.head);
	}
	return (0);
}

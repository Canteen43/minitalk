/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:17:39 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/22 10:27:17 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_cont	g_cont;

/*Main function for server.*/
int	main(void)
{
	g_cont.pid_server = getpid();
	fl_miniprint("Server PID: %d\n", g_cont.pid_server);
	while (1)
	{
		if (fl_alc_init(&g_cont.arr, ARR_CAP) == -1)
			fl_pexit("Error: g_cont.array malloc failed\n");
		g_cont.bit_char = 1;
		while (g_cont.bit_char != '\0')
		{
			f_receive_char();
			if (fl_alc_add(&g_cont.arr, g_cont.bit_char) == -1)
			{
				free(g_cont.arr.head);
				fl_pexit("Error: adding element failed\n");
			}
		}
		usleep(200);
		if (kill(g_cont.pid_client, SIGUSR1) == -1)
			fl_pexit("Error: sending confirmation failed\n");
		fl_miniprint("Received: |%s|\n", g_cont.arr.head);
		free(g_cont.arr.head);
	}
	return (0);
}

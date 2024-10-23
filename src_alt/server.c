/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:17:39 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/23 14:11:53 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

char	g_bit_char;

/*Main function for server.*/
int	main(void)
{
	t_alc	arr;
	pid_t	pid_server;

	if (f_sigint_setup() == -1)
		fl_pexit("Signal setup failed");
	pid_server = getpid();
	fl_miniprint("Server PID: %d\n", pid_server);
	while (1)
	{
		if (fl_alc_init(&arr, ARR_CAP) == -1)
			fl_pexit("Error: array malloc failed\n");
		g_bit_char = 1;
		while (g_bit_char != '\0')
		{
			f_receive_char();
			if (fl_alc_add(&arr, g_bit_char) == -1)
			{
				free(arr.head);
				fl_pexit("Error: adding element failed\n");
			}
		}
		fl_miniprint("Received: |%s|\n", arr.head);
		free(arr.head);
	}
	return (0);
}

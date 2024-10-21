/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:17:39 by kweihman          #+#    #+#             */
/*   Updated: 2024/09/17 11:17:39 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

char	g_char;

/*Main function for server.*/
int	main(void)
{
	pid_t	pid_server;
	t_alc	arr;

	pid_server = getpid();
	fl_miniprint("Server PID: %d\n", pid_server);
	while (1)
	{
		if (fl_alc_init(&arr, ARR_CAP) == -1)
			fl_pexit("Error: array malloc failed\n");
		g_char = 1;
		while (g_char != '\0')
		{
			f_receive_char();
			if (fl_alc_add(&arr, g_char) == -1)
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

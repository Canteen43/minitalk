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


char g_char;

int main (void)
{
	pid_t pid_server;
	char array[1000];
	int	i;

	pid_server = getpid();
	printf("Server PID: %d\n", pid_server); //Work on this
	while (1)
	{
		i = 0;
		g_char = 1;
		while (g_char != '\0')
		{
			f_receive_char();
			array[i] = g_char;
			i++;
		}
		printf("Received: %s|\n", array);
	}
	return (0);
}
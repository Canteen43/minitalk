/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_send_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:07:36 by kweihman          #+#    #+#             */
/*   Updated: 2024/09/17 11:07:36 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

/*Sends SIGUSR1 for 0 and SIGUSR2 for 1.*/
void	f_send_char(pid_t pid_target, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((unsigned char) c >= 128)
			if (kill(pid_target, SIGUSR2) == -1)
				fl_pexit("Sending SIGUSR2 failed");
		if ((unsigned char) c < 128)
			if (kill(pid_target, SIGUSR1) == -1)
				fl_pexit("Sending SIGUSR1 failed");
		c *= 2;
		i++;
		if (usleep(50) == -1)
			fl_pexit("Usleep failed");
	}
}

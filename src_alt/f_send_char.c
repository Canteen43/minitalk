/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_send_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:07:36 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/23 12:41:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// Static function protoypes:
static void	handler(int signum);

/*Sends SIGUSR1 for 0 and SIGUSR2 for 1.*/
void	f_send_char(pid_t pid_target, char c)
{
	int					i;
	struct sigaction	sa;

	sa.sa_handler = handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		fl_pexit("sigemptyset failed");
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		fl_pexit("sigaction 1 failed");
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
		pause();
	}
}

static void	handler(int signum)
{
	if (usleep(50) == -1)
		fl_pexit("Usleep failed");
	if (signum == SIGUSR1)
		return ;
}

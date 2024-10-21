/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_receive_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:44:25 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/21 15:53:41 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

extern char		g_char;
extern pid_t	g_pid_client;
static void		advanced_handler(int signum, siginfo_t *info, void *context);

/*Receives SIGUSR1 for 0 and SIGUSR2 for 1.*/
void	f_receive_char(void)
{
	struct sigaction	sa;
	int					i;

	sa.sa_sigaction = advanced_handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		fl_pexit("sigemptyset failed");
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		fl_pexit("sigaction 1 failed");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		fl_pexit("sigaction 2 failed");
	i = 0;
	while (i < 8)
	{
		pause();
		i++;
	}
	return ;
}

static void	advanced_handler(int signum, siginfo_t *info, void *context)
{
	char	bit;

	if (signum == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	g_char *= 2;
	g_char += bit;
	g_pid_client = info->si_pid;
	context++;
}

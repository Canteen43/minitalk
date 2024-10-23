/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_receive_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:44:25 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/23 18:42:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// Global container variable
extern t_cont	g_cont;

// Prototype, function below
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

/*Advanced handler for receiving signals that receives the bit as well as info 
about sender and saves that info to the global var.*/
static void	advanced_handler(int signum, siginfo_t *info, void *context)
{
	char	bit;

	if (usleep(50) == -1)
		fl_pexit("Usleep failed");
	if (signum == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	g_cont.bit_char *= 2;
	g_cont.bit_char += bit;
	if (kill(info->si_pid, SIGUSR1) == -1)
		fl_pexit("Sending confirmation signal failed.");
	context++;
}

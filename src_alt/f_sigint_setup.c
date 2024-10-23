/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sigint_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:11:03 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/23 18:48:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// Global container variable
extern t_cont	g_cont;

// Static function protoypes:
static void	handler(int signum);

/*Sets up signal handler for SIGINT.*/
void	f_sigint_setup(void)
{
	struct sigaction	sa_int;

	sa_int.sa_handler = handler;
	if (sigemptyset(&sa_int.sa_mask) == -1)
		fl_pexit("sigemptyset for sigint failed");
	sa_int.sa_flags = 0;
	if (sigaction(SIGINT, &sa_int, NULL) == -1)
		fl_pexit("sigaction for sigint failed");
}

static void	handler(int signum)
{
	if (signum == SIGINT)
		free(g_cont.arr.head);
	fl_miniprint("\nServer was closed with Ctrl-C. Array was freed.\n");
	exit(0);
}

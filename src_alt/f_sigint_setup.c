/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sigint_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:11:03 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/23 14:28:12 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// Static function protoypes:
static void	handler(int signum);

int	f_sigint_setup(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		fl_pexit("sigemptyset failed");
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		fl_pexit("sigaction failed");
	
}

static void	handler(int signum)
{
	// free()
	fl_miniprint("Server was closed with Ctrl-C. Array was freed.\n");
	exit(0);
}

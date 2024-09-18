/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_receive_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:44:25 by kweihman          #+#    #+#             */
/*   Updated: 2024/09/17 11:44:25 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char g_char;

/*Receives SIGUSR1 for 0 and SIGUSR2 for 1.*/
void	f_receive_char(char *c)
{
	struct sigaction sa;
    
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	while (i < 8)
	{
		pause();
		i++;
	}
	return ;
}

void	handler(int signum)
{
	char bit;

	if (signum == SIGUSR1)
		bit = 0;
	else if (signum == SIGUSR2)
		bit = 1;
	g_char *= 2;
	g_char += bit;
}
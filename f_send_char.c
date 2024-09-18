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

/*Sends SIGUSR1 for 0 and SIGUSR2 for 1.*/
f_send_char(pid_t pid_target, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >= 128)
			kill(pid_target, SIGUSR2);
		else
			kill(pid_target, SIGUSR1);
		c *= 2;
		i++;
		usleep(100);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:51:53 by kweihman          #+#    #+#             */
/*   Updated: 2024/09/18 19:51:53 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stddef.h>	// NULL
# include <signal.h>	// sigaction, sigemptyset, SIGUSR1, SIGUSR2, kill
# include <unistd.h>	// getpid, usleep

void	f_receive_char(char *c);
int		f_send_char(pid_t pid_target, char c);

#endif // MINITALK_H
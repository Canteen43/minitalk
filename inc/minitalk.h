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
# include <stdlib.h>	// malloc, free

typedef struct s_arraylist_char
{
	char*	head;
	size_t	cap;
	size_t	len;
}	t_alc;

# ifndef ARR_CAP
#  define ARR_CAP 1000
# endif

void	f_receive_char();
void	f_send_char(pid_t pid_target, char c);
void	f_pexit(char *str);
void	f_miniprint(char *str, ...);
int		f_alc_add(t_alc *arr, char c);
int		f_alc_double(t_alc *arr);
int		f_alc_init(t_alc *arr, size_t cap);

#endif // MINITALK_H
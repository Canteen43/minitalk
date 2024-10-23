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

# include <stddef.h>		// NULL
# include <signal.h>		// sigaction, sigemptyset, SIGUSR1, SIGUSR2, kill
# include <unistd.h>		// getpid, usleep
# include <stdlib.h>		// malloc, free
# include <sys/types.h>		// pid_t

typedef struct s_arraylist_char
{
	char	*head;
	size_t	cap;
	size_t	len;
}	t_alc;

// Container variable was necessary because it is not possible to free at SIGINT
// and edit the global char with just one global variable. Freeing is necessary
// to prevent memory leaks. Direct printing is forbidden. Huge stack allocation
// is stupid.
typedef struct s_container
{
	t_alc	arr;
	char	bit_char;
}	t_cont;

# ifndef ARR_CAP
#  define ARR_CAP 1000
# endif

void	f_receive_char(void);
void	f_send_char(pid_t pid_target, char c);
void	fl_pexit(char *str);
void	fl_miniprint(char *str, ...);
int		fl_alc_add(t_alc *arr, char c);
int		f_alc_double(t_alc *arr);
int		fl_alc_init(t_alc *arr, size_t cap);
void	f_sigint_setup(void);

#endif // MINITALK_H
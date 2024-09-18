/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:16:07 by kweihman          #+#    #+#             */
/*   Updated: 2024/05/15 18:40:38 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLIB_H
# define FLIB_H

# include <limits.h>	// INT_MIN and INT_MAX
# include <stddef.h>	// NULL

int f_strtoi(char *str, int *num);
int	f_lmt_check(int value, char next);

#endif // FLIB_H
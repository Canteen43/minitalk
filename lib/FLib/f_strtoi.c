/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strtoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:34:53 by kweihman          #+#    #+#             */
/*   Updated: 2024/09/17 13:34:53 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flib.h"

/*Converts a string to an integer. Returns -1 on Error and 0 on Success.
Errors include: non-digit characters, multiple minuses, number outside of INT
limits, and empty strings.
Ignores leading whitespace (' ' and '\t'), accepts one minus.*/
int f_strtoi(char *str, int *num)
{
	int sign;

	*num = 0;
	sign = 1;
	if (str == NULL)
		return (-1);
	if (*str != '\0')
		return (-1);
	while (*str == ' ' || *str == '\t')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9' && f_lmt_check(*num, *str) == 0)
			*num = *num * 10 + sign * (*str - '0');
		else
			return (-1);
		str++;
	}
	return (0);
}
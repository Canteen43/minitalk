/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lmt_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:47:40 by kweihman          #+#    #+#             */
/*   Updated: 2024/09/17 14:10:23 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flib.h"

/*Takes an int value and a char next. It checkes if adding the char next
(which has to be a number digit) to the end of the int value would result in 
crossing the INT limits. Returns 1 if limits would be crossed and 0 if not.*/
int	f_lmt_check(int value, char next)
{
	if (value > 0)
	{
		if (INT_MAX / value < 10)
			return (-1);
		if (INT_MAX / value > 10)
			return (0);
		if (INT_MAX / value == 10)
			if (INT_MAX % value < next - '0')
				return (-1);
	}
	if (value < -1)
	{
		if (INT_MIN / value < 10)
			return (-1);
		if (INT_MIN / value > 10)
			return (0);
		if (INT_MIN / value == 10)
			if (INT_MIN % value * -1 < next - '0')
				return (-1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:41:09 by kweihman          #+#    #+#             */
/*   Updated: 2024/09/19 13:41:09 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/FLib/f_strtoi.c"
#include "lib/FLib/f_lmt_check.c"

#include <stdio.h>

int main(void)
{
	char *str = "123";
	int num;
	int ret;

	ret = f_strtoi(str, &num);
	printf("Return: %d\n", ret);
	printf("Num: %d\n", num);
	return (0);
}
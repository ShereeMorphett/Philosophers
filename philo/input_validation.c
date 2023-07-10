/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:59:06 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/21 10:32:28 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_result(long long result, int sign)
{
	if (sign > 0)
		return (-1);
	else if (sign < 0)
		return (0);
	else
		return (result);
}

int	ph_atoi(const char *str)
{
	int			index;
	int			sign;
	long long	result;

	index = 0;
	sign = 1;
	result = 0;
	while (str[index] == ' ' || ((9 <= str[index]) && (str[index] <= 13)))
		index++;
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
		return (-2147483647);
	while (str[index] && ('0' <= str[index]) && (str[index] <= '9'))
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	if (result < 0)
		result = check_result(result, sign);
	return (result * sign);
}

static int	check_number(char *string)
{
	int	num;
	int	index;

	num = ph_atoi(string);
	if (num == -2147483647 || num == 0)
		return (0);
	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == '-' || string[index] == '+')
			index++;
		if (string[index] < '0' || string[index] > '9')
			return (0);
		index++;
	}
	if (string[0] != '-' && num < 0)
		return (0);
	if (string[0] == '-' && num >= 0)
		return (0);
	return (1);
}

int	process_argv(char *argv[], int argc)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (!check_number(argv[index]) && argv[index])
		{
			printf("Input must only contain positive numerical values\n");
			return (1);
		}
		index++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_max_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:25:56 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/20 18:26:16 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isaspace(const char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		return (1);
	return (0);
}

void	max_int(long *num, stack **a)
{
	if (*num > INT_MAX || *num < INT_MIN)
	{
		write(1, "Error\n", 6);
		free_stack(*a);
		exit(1);
	}
}

int	ft_atoi_max_int(const char *str, stack **a)
{
	int		i;
	int		minus;
	long	num;

	i = 0;
	minus = 0;
	num = 0;
	while (isaspace(str, i))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	if (minus == 1)
		num *= -1;
	max_int(&num, a);
	return (num);
}

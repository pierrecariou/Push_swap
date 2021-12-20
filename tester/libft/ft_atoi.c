/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:21:44 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/05 20:02:18 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isaspace(const char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	num;

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
	return (num);
}

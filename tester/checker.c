/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:30:55 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/20 17:00:13 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(stack *s)
{
	stack	*cp;

	cp = s;
	while (cp)
	{
		cp = cp->up;
		free(s);
		s = cp;
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
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
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
	if (num > INT_MAX || num < INT_MIN)
	{
		write(1, "Error\n", 6);
		free_stack(*a);
		exit(1);
	}
	return (num);
}

int	double_d(stack *s)
{
	stack	*cp;
	stack	*reset;
	int		find;

	cp = s;
	reset = s;
	while (s)
	{
		find = 0;
		while (cp)
		{
			if (cp->d == s->d)
				find++;
			cp = cp->up;
		}
		if (find > 1)
			return (1);
		s = s->up;
		cp = reset;
	}
	return (0);
}

int	check_nums(char **nums)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (nums[k])
	{
		if (!ft_strlen(nums[k]))
			return (-1);
		while (nums[k][i] && ft_isspace(nums[k][i]))
			i++;
		if (nums[k][i] && (nums[k][i] == '-' || nums[k][i] == '+'))
			i++;
		if (!nums[i])
			return (-1);
		while (nums[k][i] && ft_isdigit(nums[k][i]))
			i++;
		if (nums[k][i])
			return (-1);
		i = 0;
		k++;
	}
	return (0);
}

stack	*fill_a(stack *a, char **nums, int i)
{
	while (i >= 1)
		stack_add_back(&a, stack_new(ft_atoi_max_int(nums[i--], &a)));
	return (a);
}

int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || check_nums(argv) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	a = fill_a(a, argv, argc - 1);
	if (double_d(a))
	{
		free_stack(a);
		write(1, "Error\n", 6);
		return (1);
	}
	execute(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:30:55 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 14:51:09 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_t_stack(t_stack *s)
{
	t_stack	*cp;

	cp = s;
	while (cp)
	{
		cp = cp->up;
		free(s);
		s = cp;
	}
}

int	double_d(t_stack *s)
{
	t_stack	*cp;
	t_stack	*reset;
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

t_stack	*fill_a(t_stack *a, char **nums, int i)
{
	while (i >= 1)
		t_stack_add_back(&a, t_stack_new(ft_atoi_max_int(nums[i--], &a)));
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

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
		free_t_stack(a);
		write(1, "Error\n", 6);
		return (1);
	}
	execute(a, b);
	free_t_stack(a);
	free_t_stack(b);
	return (0);
}

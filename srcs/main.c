/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:23:11 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 15:13:16 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/*
void	show_t_stack(t_stack *s, t_stack* s1)
{
	int ca = t_stack_size(s);
	int cb = t_stack_size(s1);

	t_stack *a = t_stack_last(s);
	t_stack *b = t_stack_last(s1);
	printf("-----\n");
	if (ca >= cb)
	{
		while (a)
		{
			if (ca > cb)
				printf("%d\n", a->d);
			else {
				printf("%d%4d\n",a->d, b->d);
				b = b->down;
			}
			a = a->down;
			ca--;
		}
	}
	else
	{
		while (b)
		{
			if (cb > ca)
				printf("%5d\n", b->d);
			else {
				printf("%d%4d\n",a->d, b->d);
				a = a->down;
			}
			b = b->down;
			cb--;
		}
	}
	printf("-   -\n");
	printf("a   b\n");
	printf("-----\n");
}
*/

void	init_t_stack(t_stack **a, t_stack **b, t_stack **c, t_stack **d)
{
	*a = NULL;
	*b = NULL;
	*c = NULL;
	*d = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;
	t_stack	*d;

	init_t_stack(&a, &b, &c, &d);
	if (argc == 1 || check_nums(argv) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	a = fill_a(a, argv, argc - 1);
	c = fill_a(c, argv, argc - 1);
	if (double_d(a))
	{
		free_t_stack(a);
		write(1, "Error\n", 6);
		return (1);
	}
	algorithm(a, b, c, d);
	free_t_stack(a);
	free_t_stack(c);
	return (0);
}

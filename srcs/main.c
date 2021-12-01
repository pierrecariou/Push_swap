/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:23:11 by pcariou           #+#    #+#             */
/*   Updated: 2021/11/28 00:42:18 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(stack *s)
{
	stack *cp = s;
	while (cp)
	{
		cp = cp->up;
		free(s);
		s = cp;
	}
}

int             ft_atoi_max_int(const char *str, stack **a)
{
	int i;
	int minus;
	long num;

	i = 0;
	minus = 0;
	num = 0;
	while (str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == ' ')
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
	(minus == 1) ? num *= -1 : num;
	if (num > INT_MAX || num < INT_MIN) {
		write(1, "Error\n", 6);
		free_stack(*a);
		exit(1);
	}
	return (num);
}

int	double_d(stack *s)
{
	stack *cp;
	stack *reset;
	int find;

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

int check_nums(char **nums)
{
	int i;
	int k;

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

/*
void	show_stack(stack *s, stack* s1)
{
	int ca = stack_size(s);
	int cb = stack_size(s1);

	stack *a = stack_last(s);
	stack *b = stack_last(s1);
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

int main(int argc, char **argv)
{
	stack *a = NULL;
	stack *b = NULL;
	stack *c = NULL;
	stack *d = NULL;

	if (argc == 1 || check_nums(argv) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	a = fill_a(a, argv, argc - 1);
	c = fill_a(c, argv, argc - 1);
	if (double_d(a))
	{
		free_stack(a);
		write(1, "Error\n", 6);
		return (1);
	}

	algorithm(a, b, c, d);

	free_stack(a);
	free_stack(c);

	return (0);
}

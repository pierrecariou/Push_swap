/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:23:11 by pcariou           #+#    #+#             */
/*   Updated: 2021/11/23 21:51:25 by pcariou          ###   ########.fr       */
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
		stack_add_back(&a, stack_new(ft_atoi(nums[i--])));
	return (a);
}

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

int main(int argc, char **argv)
{
	stack *a = NULL;
	stack *b = NULL;

	if (argc == 1 || check_nums(argv) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	a = fill_a(a, argv, argc - 1);

	show_stack(a, b);
	swap(a);
	show_stack(a, b);
	push(&a, &b);
	show_stack(a, b);
	push(&a, &b);
	show_stack(a, b);
	push(&a, &b);
	show_stack(a, b);
	rotate(a);
	show_stack(a, b);
	rotate(b);
	show_stack(a, b);
	reverse_rotate(a);
	show_stack(a, b);
	reverse_rotate(b);
	show_stack(a, b);
	push(&b, &a);
	show_stack(a, b);
	push(&b, &a);
	show_stack(a, b);
	push(&b, &a);
	show_stack(a, b);

	free_stack(a);
	free_stack(b);

	return (0);
}

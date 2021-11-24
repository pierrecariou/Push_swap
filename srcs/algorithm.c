/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:00:39 by pcariou           #+#    #+#             */
/*   Updated: 2021/11/24 19:19:51 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		min(stack *s)
{
	int d;
	int index;
	int ret;
	int size;

	d = s->d;
	index = 1;
	ret = 1;
	size = stack_size(s);
	while (s)
	{
		if (d > s->d) {
			d = s->d;
			ret = index;
		}
		s = s->up;
		index++;
	}
	return (size - ret);
}

int		max(stack *s)
{
	int d;
	int index;
	int ret;
	int size;

	d = s->d;
	index = 1;
	ret = 1;
	size = stack_size(s);
	while (s)
	{
		if (d < s->d) {
			d = s->d;
			ret = index;
		}
		s = s->up;
		index++;
	}
	return (size - ret);
}

int		sorted(stack *a)
{
	while (a->up)
	{
		if (a->d < a->up->d)
			return (0);
		a = a->up;
	}
	return (1);
}

void	sort_hundred(stack **a, stack **b)
{
	while (stack_size(*a) != 0)
	{
		if (min(*a) <= stack_size(*a) / 2)
			multiple_op(*a, "ra\n", min(*a), rotate);
		else
			multiple_op(*a, "rra\n", stack_size(*a) - min(*a), reverse_rotate);
		push(a, b, "pb\n");
	}
	while (stack_size(*b) != 0)
		push(b, a, "pa\n");
}

void	sort_three(stack *a)
{
	if (stack_last(a)->down->d < stack_last(a)->d && stack_last(a)->down->d < a->d)
	{
		if (stack_last(a)->d < a->d)
			swap(a, "sa\n");
		else
			rotate(a, "ra\n");
	}
	else if (stack_last(a)->down->d > stack_last(a)->d && stack_last(a)->down->d > a->d)
	{
		if (stack_last(a)->d < a->d)
		{
			swap(a, "sa\n");
			rotate(a, "ra\n");
		}
		else
			reverse_rotate(a, "rra\n");
	}
	else if (stack_last(a)->down->d < stack_last(a)->d)
	{
		swap(a, "sa\n");
		reverse_rotate(a, "rra\n");
	}
}

void	sort_five(stack **a, stack **b)
{
	if (max(*a) <= stack_size(*a) / 2)
		multiple_op(*a, "ra\n", max(*a), rotate);
	else
		multiple_op(*a, "rra\n", stack_size(*a) - max(*a), reverse_rotate);
	push(a, b, "pb\n");
	if (stack_size(*a) > 3) {
		if (min(*a) <= stack_size(*a) / 2)
			multiple_op(*a, "ra\n", min(*a), rotate);
		else
			multiple_op(*a, "rra\n", stack_size(*a) - min(*a), reverse_rotate);
		push(a, b, "pb\n");
	}
	sort_three(*a);
	push(b, a, "pa\n");
	if (stack_size(*b) != 0)
		push(b, a, "pa\n");
	rotate(*a, "ra\n");
}

void	algorithm(stack *a, stack *b)
{
	int size = stack_size(a);
	if (size == 2 && stack_last(a)->d > a->d)
		swap(a, "sa\n");
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_five(&a, &b);
	else if (size > 5 && size <= 100)
		sort_hundred(&a, &b);
	//show_stack(a, b);
	return ;
}

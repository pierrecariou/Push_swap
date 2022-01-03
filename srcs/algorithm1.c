/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:10:14 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 15:12:53 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	delete_found(t_stack *a, t_stack **d, int index, int bottom)
{
	int	i;

	i = 1;
	if (bottom == 1)
	{
		while (a)
		{
			if (i == index)
				del_one_chunk(a->d, d);
			i++;
			a = a->up;
		}
	}
	else
	{
		a = t_stack_last(a);
		while (a)
		{
			if (i == index)
				del_one_chunk(a->d, d);
			i++;
			a = a->down;
		}
	}
}

void	pre_sort(t_stack **a, t_stack **b, t_stack **d, int size_c)
{
	int	from_bottom;
	int	from_up;

	while (size_c > 0)
	{
		from_bottom = find_from_bottom(*a, *d, size_c);
		from_up = find_from_up(*a, *d, size_c);
		if (from_bottom < from_up)
		{
			delete_found(*a, d, from_bottom, 1);
			multiple_op(*a, "rra\n", from_bottom, reverse_rotate);
		}
		else
		{
			delete_found(*a, d, from_up, 0);
			multiple_op(*a, "ra\n", from_up - 1, rotate);
		}
		push(a, b, "pb\n");
		size_c--;
	}
}

void	refill_a(t_stack **a, t_stack **b)
{
	while (t_stack_size(*b) != 0)
	{
		if (max(*b) <= t_stack_size(*b) / 2)
			multiple_op(*b, "rb\n", max(*b), rotate);
		else
			multiple_op(*b, "rrb\n", t_stack_size(*b) - max(*b), reverse_rotate);
		push(b, a, "pa\n");
	}
}

void	sort_medium(t_stack **a, t_stack **b, t_stack **c, t_stack **d)
{
	int	i;
	int	size_c;

	size_c = t_stack_size(*a) / 5;
	i = 0;
	sort_chunk(c, d);
	while (i++ < 4)
		pre_sort(a, b, d, size_c);
	size_c = t_stack_size(*d);
	pre_sort(a, b, d, size_c);
	refill_a(a, b);
}

void	sort_big(t_stack **a, t_stack **b, t_stack **c, t_stack **d)
{
	int	i;
	int	size_c;

	size_c = t_stack_size(*a) / 11;
	i = 0;
	sort_chunk(c, d);
	while (i++ < 10)
		pre_sort(a, b, d, size_c);
	size_c = t_stack_size(*d);
	pre_sort(a, b, d, size_c);
	refill_a(a, b);
}

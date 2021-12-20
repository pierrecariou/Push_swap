/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:10:21 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/20 18:12:13 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_from_up(stack *s, stack *d, int size_c)
{
	int	index;

	index = 1;
	s = stack_last(s);
	while (s)
	{
		if (contains(s->d, d, size_c))
			return (index);
		index++;
		s = s->down;
	}
	return (0);
}

int	sorted(stack *a)
{
	while (a->up)
	{
		if (a->d < a->up->d)
			return (0);
		a = a->up;
	}
	return (1);
}

void	sort_small(stack **a, stack **b)
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

void	sort_chunk(stack **c, stack **d)
{
	while (stack_size(*c) != 0)
	{
		if (min(*c) <= stack_size(*c) / 2)
			multiple_op(*c, "", min(*c), rotate);
		else
			multiple_op(*c, "", stack_size(*c) - min(*c), reverse_rotate);
		push(c, d, "");
	}
	while (stack_size(*c) != 0)
		push(c, d, "");
}

void	del_one_chunk(int digit, stack **d)
{
	stack	*cp_up;
	stack	*cp_down;
	stack	*cp;

	cp = *d;
	while (*d)
	{
		if ((*d)->d == digit)
		{
			cp_up = (*d)->up;
			cp_down = (*d)->down;
			free(*d);
			if (cp_up != 0)
				cp_up->down = cp_down;
			if (cp_down != 0)
			{
				cp_down->up = cp_up;
				*d = cp;
			}
			else
				*d = cp_up;
			return ;
		}
		*d = (*d)->up;
	}
}

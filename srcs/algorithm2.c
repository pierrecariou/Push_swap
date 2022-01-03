/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:10:21 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 15:12:59 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_from_up(t_stack *s, t_stack *d, int size_c)
{
	int	index;

	index = 1;
	s = t_stack_last(s);
	while (s)
	{
		if (contains(s->d, d, size_c))
			return (index);
		index++;
		s = s->down;
	}
	return (0);
}

int	sorted(t_stack *a)
{
	while (a->up)
	{
		if (a->d < a->up->d)
			return (0);
		a = a->up;
	}
	return (1);
}

void	sort_small(t_stack **a, t_stack **b)
{
	while (t_stack_size(*a) != 0)
	{
		if (min(*a) <= t_stack_size(*a) / 2)
			multiple_op(*a, "ra\n", min(*a), rotate);
		else
			multiple_op(*a, "rra\n", t_stack_size(*a) - min(*a), reverse_rotate);
		push(a, b, "pb\n");
	}
	while (t_stack_size(*b) != 0)
		push(b, a, "pa\n");
}

void	sort_chunk(t_stack **c, t_stack **d)
{
	while (t_stack_size(*c) != 0)
	{
		if (min(*c) <= t_stack_size(*c) / 2)
			multiple_op(*c, "", min(*c), rotate);
		else
			multiple_op(*c, "", t_stack_size(*c) - min(*c), reverse_rotate);
		push(c, d, "");
	}
	while (t_stack_size(*c) != 0)
		push(c, d, "");
}

void	del_one_chunk(int digit, t_stack **d)
{
	t_stack	*cp_up;
	t_stack	*cp_down;
	t_stack	*cp;

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

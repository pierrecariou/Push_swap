/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:47:52 by pcariou           #+#    #+#             */
/*   Updated: 2021/11/23 21:50:14 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(stack *s)
{
	int size = stack_size(s);

	write(1, "sa\n", 3);
	if (size == 0 || size == 1)
		return ;
	stack *last = stack_last(s);
	int cp = last->down->d;

	last->down->d = last->d;
	last->d = cp;
}

void	push(stack **s, stack **s1)
{
	int size = stack_size(*s);

	write(1, "pb\n", 3);
	if (size == 0)
		return ;
	stack *last = stack_last(*s);
	stack_add_back(s1, stack_new(last->d));
	if (last->down)
		last->down->up = 0;
	else
		*s = NULL;
	free(last);
}


void	rotate(stack *s)
{
	int size = stack_size(s);

	write(1, "ra\n", 3);
	if (size == 0 || size == 1)
		return ;
	stack *last = stack_last(s);
	int front = last->d;
	while (last->down)
	{
		last->d = last->down->d;
		last = last->down;
	}
	last->d = front;
}

void	reverse_rotate(stack *s)
{
	int size = stack_size(s);

	write(1, "rra\n", 4);
	if (size == 0 || size == 1)
		return ;
	stack *first = s;
	int back = first->d;
	while (first->up)
	{
		first->d = first->up->d;
		first = first->up;
	}
	first->d = back;

}

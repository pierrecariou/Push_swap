/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:47:52 by pcariou           #+#    #+#             */
/*   Updated: 2021/11/26 19:42:09 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(stack *s, char *op)
{
	int size = stack_size(s);

	write(1, op, ft_strlen(op));
	if (size == 0 || size == 1)
		return ;
	stack *last = stack_last(s);
	int cp = last->down->d;

	last->down->d = last->d;
	last->d = cp;
}

void	ss(stack *s, stack *s1)
{
	swap(s, "sa\n");
	swap(s1, "sb\n");
}

void	push(stack **s, stack **s1, char *op)
{
	int size = stack_size(*s);

	write(1, op, ft_strlen(op));
	if (size == 0)
		return ;
	stack *last = stack_last(*s);
	if (last->down)
		last->down->up = 0;
	else
		*s = NULL;
	if (!*s1) {
		*s1 = last;
		(*s1)->down = 0;
		(*s1)->up = 0;
		return ;
	}
	stack *last1 = stack_last(*s1);
	last1->up = last;
	last->down = last1;
}


void	rotate(stack *s, char *op)
{
	int size = stack_size(s);

	write(1, op, ft_strlen(op));
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

void	rr(stack *s, stack *s1)
{
	rotate(s, "ra\n");
	rotate(s1, "rb\n");
}

void	reverse_rotate(stack *s, char *op)
{
	int size = stack_size(s);

	write(1, op, ft_strlen(op));
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

void	rrr(stack *s, stack *s1)
{
	reverse_rotate(s, "rra\n");
	reverse_rotate(s1, "rrb\n");
}

void	multiple_op(stack *s, char *op, int num, void(*f)(stack *s, char *op))
{
	int i;

	i = 0;
	while (i++ < num)
		f(s, op);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:47:52 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 15:05:57 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *s, char *op)
{
	int		size;
	int		cp;
	t_stack	*last;

	size = t_stack_size(s);
	write(1, op, ft_strlen(op));
	if (size == 0 || size == 1)
		return ;
	last = t_stack_last(s);
	cp = last->down->d;
	last->down->d = last->d;
	last->d = cp;
}

void	ss(t_stack *s, t_stack *s1)
{
	swap(s, "sa\n");
	swap(s1, "sb\n");
}

void	push(t_stack **s, t_stack **s1, char *op)
{
	int		size;
	t_stack	*last;
	t_stack	*last1;

	size = t_stack_size(*s);
	write(1, op, ft_strlen(op));
	if (size == 0)
		return ;
	last = t_stack_last(*s);
	if (last->down)
		last->down->up = 0;
	else
		*s = NULL;
	if (!*s1)
	{
		*s1 = last;
		(*s1)->down = 0;
		(*s1)->up = 0;
		return ;
	}
	last1 = t_stack_last(*s1);
	last1->up = last;
	last->down = last1;
}

void	rotate(t_stack *s, char *op)
{
	int		size;
	int		front;
	t_stack	*last;

	size = t_stack_size(s);
	write(1, op, ft_strlen(op));
	if (size == 0 || size == 1)
		return ;
	last = t_stack_last(s);
	front = last->d;
	while (last->down)
	{
		last->d = last->down->d;
		last = last->down;
	}
	last->d = front;
}

void	rr(t_stack *s, t_stack *s1)
{
	rotate(s, "ra\n");
	rotate(s1, "rb\n");
}

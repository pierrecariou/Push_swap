/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:00:51 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/20 18:01:33 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(stack *s, char *op)
{
	int		size;
	int		back;
	stack	*first;

	size = stack_size(s);
	write(1, op, ft_strlen(op));
	if (size == 0 || size == 1)
		return ;
	first = s;
	back = first->d;
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

void	multiple_op(stack *s, char *op, int num, void (*f)(stack *s, char *op))
{
	int	i;

	i = 0;
	while (i++ < num)
		f(s, op);
}

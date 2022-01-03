/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:05:39 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 15:06:09 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_stack *s, char *op)
{
	int		size;
	int		back;
	t_stack	*first;

	size = t_stack_size(s);
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

void	rrr(t_stack *s, t_stack *s1)
{
	reverse_rotate(s, "rra\n");
	reverse_rotate(s1, "rrb\n");
}

void	multiple_op(t_stack *s, char *op, int num
			, void (*f)(t_stack *s, char *op))
{
	int	i;

	i = 0;
	while (i++ < num)
		f(s, op);
}

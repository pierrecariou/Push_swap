/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:10:26 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/20 18:12:39 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min(stack *s)
{
	int	d;
	int	index;
	int	ret;
	int	size;

	d = s->d;
	index = 1;
	ret = 1;
	size = stack_size(s);
	while (s)
	{
		if (d > s->d)
		{
			d = s->d;
			ret = index;
		}
		s = s->up;
		index++;
	}
	return (size - ret);
}

int	max(stack *s)
{
	int	d;
	int	index;
	int	ret;
	int	size;

	d = s->d;
	index = 1;
	ret = 1;
	size = stack_size(s);
	while (s)
	{
		if (d < s->d)
		{
			d = s->d;
			ret = index;
		}
		s = s->up;
		index++;
	}
	return (size - ret);
}

int	contains(int d, stack *s, int size_c)
{
	int	index;

	index = 0;
	while (s && index < size_c)
	{
		if (d == s->d)
			return (1);
		s = s->up;
		index++;
	}
	return (0);
}

int	find_from_bottom(stack *s, stack *d, int size_c)
{
	int	index;

	index = 1;
	while (s)
	{
		if (contains(s->d, d, size_c))
			return (index);
		index++;
		s = s->up;
	}
	return (0);
}

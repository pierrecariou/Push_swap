/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:47:52 by pcariou           #+#    #+#             */
/*   Updated: 2021/11/23 18:12:48 by pcariou          ###   ########.fr       */
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

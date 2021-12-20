/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:26:25 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/05 20:34:23 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack	*stack_new(int d)
{
	stack	*elem;

	elem = malloc(sizeof(stack));
	if (!elem)
		return (0);
	elem->d = d;
	elem->up = 0;
	elem->down = 0;
	return (elem);
}

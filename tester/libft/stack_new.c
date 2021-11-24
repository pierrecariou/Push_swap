/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:26:25 by pcariou           #+#    #+#             */
/*   Updated: 2021/11/23 18:08:11 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack	*stack_new(int d)
{
	stack	*elem;

	if (!(elem = malloc(sizeof(stack))))
		return (0);
	elem->d = d;
	elem->up = 0;
	elem->down = 0;
	return (elem);
}

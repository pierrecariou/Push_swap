/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:18:15 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/05 20:13:08 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stack_add_back(stack **alst, stack *new)
{
	stack	*elem;

	if (!new)
		return ;
	if (!alst || !*alst)
	{
		*alst = new;
		return ;
	}
	elem = *alst;
	while (elem->up)
		elem = elem->up;
	elem->up = new;
	new->down = elem;
}

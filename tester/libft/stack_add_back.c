/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:18:15 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 14:46:17 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	t_stack_add_back(t_stack **alst, t_stack *new)
{
	t_stack	*elem;

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

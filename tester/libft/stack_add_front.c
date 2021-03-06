/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:33:34 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 14:46:31 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	t_stack_add_front(t_stack **alst, t_stack *new)
{
	new->up = *alst;
	(*alst)->down = new;
	*alst = new;
}

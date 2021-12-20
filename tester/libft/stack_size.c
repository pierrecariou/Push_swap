/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:10:30 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/05 20:22:38 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	stack_size(stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->up;
		count++;
	}
	return (count);
}

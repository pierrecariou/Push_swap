/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:10:30 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 15:10:33 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	t_stack_size(t_stack *lst)
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

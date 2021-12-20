/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:40:58 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/20 17:02:13 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include "libft/libft.h"

void	swap(stack *s, char *op);
void	ss(stack *s, stack *s1);
void	push(stack **s, stack **s1, char *op);
void	rotate(stack *s, char *op);
void	rr(stack *s, stack *s1);
void	reverse_rotate(stack *s, char *op);
void	rrr(stack *s, stack *s1);
void	algorithm(stack *a, stack *b);
void	multiple_op(stack *s, char *op, int num, void (*f)(stack *s, char *op));

void	show_stack(stack *a, stack *b);

void	execute(stack *a, stack *b);

#endif

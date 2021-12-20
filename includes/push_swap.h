/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:40:58 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/20 18:19:04 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// operations
void	swap(stack *s, char *op);
void	ss(stack *s, stack *s1);
void	push(stack **s, stack **s1, char *op);
void	rotate(stack *s, char *op);
void	rr(stack *s, stack *s1);
void	reverse_rotate(stack *s, char *op);
void	rrr(stack *s, stack *s1);
void	algorithm(stack *a, stack *b, stack *c, stack *d);
void	multiple_op(stack *s, char *op, int num, void (*f)(stack *s, char *op));

void	show_stack(stack *a, stack *b);

// algorithm
int		find_from_up(stack *s, stack *d, int size_c);
int		find_from_bottom(stack *s, stack *d, int size_c);
int		min(stack *s);
int		max(stack *s);
void	sort_small(stack **a, stack **b);
void	sort_medium(stack **a, stack **b, stack **c, stack **d);
void	sort_big(stack **a, stack **b, stack **c, stack **d);
void	del_one_chunk(int digit, stack **d);
void	sort_chunk(stack **c, stack **d);
int		contains(int d, stack *s, int size_c);

#endif

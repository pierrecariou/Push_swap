/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:40:58 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 15:14:35 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// operations
void	swap(t_stack *s, char *op);
void	ss(t_stack *s, t_stack *s1);
void	push(t_stack **s, t_stack **s1, char *op);
void	rotate(t_stack *s, char *op);
void	rr(t_stack *s, t_stack *s1);
void	reverse_rotate(t_stack *s, char *op);
void	rrr(t_stack *s, t_stack *s1);
void	algorithm(t_stack *a, t_stack *b, t_stack *c, t_stack *d);
void	multiple_op(t_stack *s, char *op, int num,
			void (*f)(t_stack *s, char *op));

void	show_t_stack(t_stack *a, t_stack *b);

// algorithm
int		find_from_up(t_stack *s, t_stack *d, int size_c);
int		find_from_bottom(t_stack *s, t_stack *d, int size_c);
int		min(t_stack *s);
int		max(t_stack *s);
void	sort_small(t_stack **a, t_stack **b);
void	sort_medium(t_stack **a, t_stack **b, t_stack **c, t_stack **d);
void	sort_big(t_stack **a, t_stack **b, t_stack **c, t_stack **d);
void	del_one_chunk(int digit, t_stack **d);
void	sort_chunk(t_stack **c, t_stack **d);
int		contains(int d, t_stack *s, int size_c);

#endif

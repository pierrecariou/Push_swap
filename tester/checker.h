/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:40:58 by pcariou           #+#    #+#             */
/*   Updated: 2022/01/03 14:55:44 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"

void	swap(t_stack *s, char *op);
void	ss(t_stack *s, t_stack *s1);
void	push(t_stack **s, t_stack **s1, char *op);
void	rotate(t_stack *s, char *op);
void	rr(t_stack *s, t_stack *s1);
void	reverse_rotate(t_stack *s, char *op);
void	rrr(t_stack *s, t_stack *s1);
void	algorithm(t_stack *a, t_stack *b);
void	multiple_op(t_stack *s, char *op, int num,
			void (*f)(t_stack *s, char *op));

void	show_t_stack(t_stack *a, t_stack *b);

void	execute(t_stack *a, t_stack *b);
int		ft_atoi_max_int(const char *str, t_stack **a);

#endif

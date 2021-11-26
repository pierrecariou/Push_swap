/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:00:39 by pcariou           #+#    #+#             */
/*   Updated: 2021/11/26 16:37:27 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		min(stack *s)
{
	int d;
	int index;
	int ret;
	int size;

	d = s->d;
	index = 1;
	ret = 1;
	size = stack_size(s);
	while (s)
	{
		if (d > s->d) {
			d = s->d;
			ret = index;
		}
		s = s->up;
		index++;
	}
	return (size - ret);
}

int		max(stack *s)
{
	int d;
	int index;
	int ret;
	int size;

	d = s->d;
	index = 1;
	ret = 1;
	size = stack_size(s);
	while (s)
	{
		if (d < s->d) {
			d = s->d;
			ret = index;
		}
		s = s->up;
		index++;
	}
	return (size - ret);
}

int		contains(int d, stack *s, int size_c)
{
	int index;

	index = 0;
	while (s && index < size_c)
	{
		//printf("d: %d\n", s->d);
		if (d == s->d)
			return (1);
		s = s->up;
		index++;
	}
	return (0);
}

int		find_from_bottom(stack *s, stack *d, int size_c)
{
	int index;

	index = 1;
	while (s)
	{
		if (contains(s->d, d, size_c))
			return (index);
		index++;
		s = s->up;
	}
	return (0);
}

int		find_from_up(stack *s, stack *d, int size_c)
{
	int index;

	index = 1;
	s = stack_last(s);
	while (s)
	{
		if (contains(s->d, d, size_c))
			return (index);
		index++;
		s = s->down;
	}
	return (0);
}

int		sorted(stack *a)
{
	while (a->up)
	{
		if (a->d < a->up->d)
			return (0);
		a = a->up;
	}
	return (1);
}

void	sort_small(stack **a, stack **b)
{
	while (stack_size(*a) != 0)
	{
		if (min(*a) <= stack_size(*a) / 2)
			multiple_op(*a, "ra\n", min(*a), rotate);
		else
			multiple_op(*a, "rra\n", stack_size(*a) - min(*a), reverse_rotate);
		push(a, b, "pb\n");
	}
	while (stack_size(*b) != 0)
		push(b, a, "pa\n");
	//test
	/*

	   push(a, b, "pb\n");
	   while(stack_size(*a) != 0)
	   {
	//int temp_value = input_stack.top()
	int tmp;

	tmp = stack_last(*a)->d;
	rotate(*a, "ra\n");
	while(stack_size(*b) != 0 && stack_last(*b)->d > tmp)
	push(b, a, "pa\n");
	reverse_rotate(*a, "rra\n");
	push(a, b, "pb\n");

	//aux_stack.push(temp_value)
	}
	while (stack_size(*b) != 0)
	push(b, a, "pa\n");
	 */
}

void	sort_chunk(stack **c, stack **d)
{
	while (stack_size(*c) != 0)
	{
		if (min(*c) <= stack_size(*c) / 2)
			multiple_op(*c, "", min(*c), rotate);
		else
			multiple_op(*c, "", stack_size(*c) - min(*c), reverse_rotate);
		push(c, d, "");
	}
	while (stack_size(*c) != 0)
		push(c, d, "");
}

void	del_one_chunk(int digit, stack **d)
{
	stack *cp_up;
	stack *cp_down;
	stack *cp;

	cp = *d;
	while (*d)
	{

		//printf("TEST %p %p %d %d\n", (*d)->down, (*d)->up, (*d)->d, digit);
		if ((*d)->d == digit)
		{
			//printf("TEST %p %p\n", (*d)->down, (*d)->up);
			cp_up = (*d)->up;
			cp_down = (*d)->down;
			free(*d);
			if (cp_up != 0)
				cp_up->down = cp_down;
			if (cp_down != 0) {
				//printf("TESTOINS\n");
				cp_down->up = cp_up;
				*d = cp;
			}
			else
				*d = cp_up;
			return ;
		}
		*d = (*d)->up;
	}
}

void	delete_found(stack *a, stack **d, int index, int bottom)
{
	int i;

	i = 1;
	if (bottom == 1)
	{
		while (a)
		{
			if (i == index)
				del_one_chunk(a->d, d);
			i++;	
			a = a->up;
		}
	}
	else
	{
		a = stack_last(a);
		while (a)
		{
			if (i == index)
				del_one_chunk(a->d, d);
			i++;
			a = a->down;
		}

	}
}

void	pre_sort(stack **a, stack **b, stack **d, int size_c)
{
	int from_bottom;
	int from_up;

	while (size_c > 0)
	{

	//printf("size_c: %d\n", size_c);
		from_bottom = find_from_bottom(*a, *d, size_c);
		from_up = find_from_up(*a, *d, size_c);
		//printf("bottom = %d\n", from_bottom);
		//printf("up     = %d\n", from_up);
		if (from_bottom < from_up) {
			delete_found(*a, d, from_bottom, 1);
			multiple_op(*a, "rra\n", from_bottom, reverse_rotate);
		}
		else {
			delete_found(*a, d, from_up, 0);
			multiple_op(*a, "ra\n", from_up - 1, rotate);
		}
		push(a, b, "pb\n");
		/*
		cp = (*d)->up;
		free(*d);
		*d = cp;
		if (cp)
			(*d)->down = 0;
			*/
		size_c--;
	}
	(void)b;
}

void	refill_a(stack **a, stack **b)
{
	while (stack_size(*b) != 0)
	{
		if (max(*b) <= stack_size(*b) / 2)
			multiple_op(*b, "rb\n", max(*b), rotate);
		else
			multiple_op(*b, "rrb\n", stack_size(*b) - max(*b), reverse_rotate);
		push(b, a, "pa\n");
	}
			
}

void	sort_medium(stack **a, stack **b, stack **c, stack **d)
{
	int i;
	int size_c;

	size_c = stack_size(*a) / 5;
	i = 0;

	sort_chunk(c, d);
//	show_stack(*c, *d);
/*
	printf("STACK A_B\n");
	show_stack(*a, *b);
	printf("STACK C_D\n");
	show_stack(*c, *d);
	*/

	//printf("%d\n", size_c);
	while (i++ < 4){
		pre_sort(a, b, d, size_c);
		/*
		printf("STACK A_B\n");
		show_stack(*a, *b);
		printf("STACK C_D\n");
		show_stack(*c, *d);
		*/
	}
	size_c = stack_size(*d);
	//printf("size_c: %d\n", size_c);
	pre_sort(a, b, d, size_c);	
	/*
	printf("STACK A_B\n");
		show_stack(*a, *b);
		printf("STACK C_D\n");
		show_stack(*c, *d);
		*/
	refill_a(a, b);
//printf("STACK A_B\n");
//		show_stack(*a, *b);
}

void	sort_three(stack *a)
{
	if (stack_last(a)->down->d < stack_last(a)->d && stack_last(a)->down->d < a->d)
	{
		if (stack_last(a)->d < a->d)
			swap(a, "sa\n");
		else
			rotate(a, "ra\n");
	}
	else if (stack_last(a)->down->d > stack_last(a)->d && stack_last(a)->down->d > a->d)
	{
		if (stack_last(a)->d < a->d)
		{
			swap(a, "sa\n");
			rotate(a, "ra\n");
		}
		else
			reverse_rotate(a, "rra\n");
	}
	else if (stack_last(a)->down->d < stack_last(a)->d)
	{
		swap(a, "sa\n");
		reverse_rotate(a, "rra\n");
	}
}

void	sort_five(stack **a, stack **b)
{
	if (max(*a) <= stack_size(*a) / 2)
		multiple_op(*a, "ra\n", max(*a), rotate);
	else
		multiple_op(*a, "rra\n", stack_size(*a) - max(*a), reverse_rotate);
	push(a, b, "pb\n");
	if (stack_size(*a) > 3) {
		if (min(*a) <= stack_size(*a) / 2)
			multiple_op(*a, "ra\n", min(*a), rotate);
		else
			multiple_op(*a, "rra\n", stack_size(*a) - min(*a), reverse_rotate);
		push(a, b, "pb\n");
	}
	sort_three(*a);
	push(b, a, "pa\n");
	if (stack_size(*b) != 0)
		push(b, a, "pa\n");
	rotate(*a, "ra\n");
}

void	algorithm(stack *a, stack *b, stack *c, stack *d)
{
	int size = stack_size(a);
	if (size == 2 && stack_last(a)->d > a->d)
		swap(a, "sa\n");
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_five(&a, &b);
	else if (size > 5 && size <= 50)
		sort_small(&a, &b);
	else if (size > 50 && size <= 500)
		sort_medium(&a, &b, &c, &d);

	//	show_stack(a, b);	
}

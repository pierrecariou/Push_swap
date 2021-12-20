/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:16:31 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/20 17:09:42 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_next_line(char **line)
{	
	char	buf[2];
	int		ret;
	int		i;

	i = 0;
	*line = malloc(200000);
	if (!line)
		exit (1);
	ret = read(0, buf, 1);
	while (ret && buf[0] != '\n')
	{
		line[0][i++] = buf[0];
		ret = read(0, buf, 1);
	}
	line[0][i] = 0;
	return (ret);
}

int	sorted(stack *a)
{
	while (a->up)
	{
		if (a->d < a->up->d)
			return (0);
		a = a->up;
	}
	return (1);
}

void	exec_op(char *line, stack **a, stack **b)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		swap(*a, "sa\n");
	if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		swap(*b, "sb\n");
	if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		push(b, a, "pa\n");
	if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		push(a, b, "pb\n");
	if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		rotate(*a, "ra\n");
	if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		rotate(*b, "rb\n");
	if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		reverse_rotate(*a, "rra\n");
	if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		reverse_rotate(*b, "rrb\n");
}

void	check_result(stack *a)
{
	if (sorted(a))
	{
		write(1, "\033[0;32m", 7);
		write(1, "OK\n", 3);
		write(1, "\033[0;37m", 7);
	}
	else
	{
		write(1, "\033[0;31m", 7);
		write(1, "KO\n", 3);
		write(1, "\033[0;37m", 7);
	}
}

void	execute(stack *a, stack *b)
{
	int		r;
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	r = get_next_line(&line);
	while (r > 0)
	{
		exec_op(line, &a, &b);
		free(line);
		line = NULL;
		i++;
		r = get_next_line(&line);
	}
	free(line);
	line = NULL;
	check_result(a);
}

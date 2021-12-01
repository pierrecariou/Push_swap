/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:16:31 by pcariou           #+#    #+#             */
/*   Updated: 2021/11/28 00:54:20 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_next_line(char **line)
{	
	char	buf[2];
	int		ret;
	int		i = 0;

	if (!(*line = malloc(200000)))
		exit (1);
	while ((ret = read(0, buf, 1)) && buf[0] != '\n')
		line[0][i++] = buf[0];
	line[0][i] = 0;
	return (ret);
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

void	execute(stack *a, stack *b)
{
	int		r;
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while ((r = get_next_line(&line)) > 0)
	{
		exec_op(line, &a, &b);
		free(line);
		line = NULL;
		i++;
	}
	free(line);
	line = NULL;
	if (sorted(a)) {
		write(1, "\033[0;32m", 7);
		write(1, "OK\n", 3);
		write(1, "\033[0;37m", 7);
	}
	else {
		write(1, "\033[0;31m", 7);
		write(1, "KO\n", 3);
		write(1, "\033[0;37m", 7);
	}
}

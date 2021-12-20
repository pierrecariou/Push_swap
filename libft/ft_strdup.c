/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:11:40 by pcariou           #+#    #+#             */
/*   Updated: 2021/12/05 20:07:49 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	while ((s1)[len])
		len++;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = (s1)[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

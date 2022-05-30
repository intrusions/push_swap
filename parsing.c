/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 03:27:30 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/28 17:14:15 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9') )
		return (1);
	return (0);
}

int ft_parsing(char **argv, int len)
{
	int	i;
	int	j;
	
	i = 1;
	while (i <= len)
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicate_and_max(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] == stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_fill_stack(int *stack, int len, char **argv)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}
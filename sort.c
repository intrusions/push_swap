/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:19:14 by xel               #+#    #+#             */
/*   Updated: 2022/05/28 17:19:14 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sorted(int *stack, int len)
{
	int  i;
	int  j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] > stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void    ft_replace_per_index(int *stack, int len)
{
	(void)stack;
	(void)len;
}

void	ft_sort_small_stack(t_data *data)
{
	(void)data;
}

int	ft_sort_big_stack(t_data *data)
{
	int	j;
	int	size;
	int	max_bits;
	int	to_max_bits;
	
	max_bits = 0;
	size = data->len_a - 1;
	to_max_bits = 0;
	while (data->len_a >> max_bits != 0)
		max_bits++;
	while (to_max_bits < max_bits)
	{
		j = 0;
		while (j <= size)
		{
			if ((data->stack_a[0] >> to_max_bits) & (1 == 1))
				ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
			else
				if (!ft_push_pb(data))
					return (0);
			j++;
		}
		while (data->len_b)
			ft_push_pa(data);
		to_max_bits++;
	}
	return (1);
}

int ft_sort(t_data *data)
{
	if (ft_is_sorted(data->stack_a, data->len_a))
		return (0);
	ft_replace_per_index(data->stack_a, data->len_a);
	if (data->len_a <= 5)
		ft_sort_small_stack(data);
	else
		if (!ft_sort_big_stack(data))
			return (0);
	return (1);
}
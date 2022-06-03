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

void	ft_sort_for_index(int **new_stack, int len)
{
	int	*tmp;
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (*new_stack[i] > *new_stack[j])
			{
				tmp = new_stack[i];
				new_stack[i] = new_stack[j];
				new_stack[j] = tmp;
			}
			j++;
		}
	}
}

int	ft_replace_per_index(int *stack, int len)
{
	int		**new_stack;
	int		i;

	i = -1;
	new_stack = malloc(sizeof(int *) * len);
	if (!new_stack)
		return (0);
	while (++i < len)
		new_stack[i] = &stack[i];
	ft_sort_for_index(new_stack, len);
	i = -1;
	while (++i < len)
		*new_stack[i] = i;
	free(new_stack);
	return (1);
}

int	ft_get_max_bits(t_data *data)
{
	int	max_bits;

	max_bits = 0;
	while (data->len_a >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

int	ft_sort_big_stack(t_data *data)
{
	int	j;
	int	size;
	int	max_bits;
	int	to_max_bits;

	max_bits = ft_get_max_bits(data);
	size = data->len_a - 1;
	to_max_bits = -1;
	while (++to_max_bits < max_bits)
	{
		j = -1;
		while (++j <= size)
		{
			if ((data->stack_a[0] >> to_max_bits) & (1 == 1))
				ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
			else
				if (!ft_push_pb(data))
					return (0);
		}
		while (data->len_b)
			if (!ft_push_pa(data))
				return (0);
	}
	return (1);
}

int	ft_sort(t_data *data)
{
	if (ft_is_sorted(data->stack_a, data->len_a))
		return (0);
	ft_replace_per_index(data->stack_a, data->len_a);
	if (data->len_a <= 5)
	{
		if (!ft_sort_small_stack(data))
			return (0);
	}
	else
	{
		if (!ft_sort_big_stack(data))
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:56:18 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/31 19:42:25 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_data *data)
{
	if ((data->stack_a[0] < data->stack_a[2])
		&& (data->stack_a[0] > data->stack_a[1]))
		ft_swap_sa_sb(data->stack_a, data->len_a, _STACK_A, TRUE);
	else if ((data->stack_a[0] > data->stack_a[1])
		&& (data->stack_a[1] > data->stack_a[2]))
	{
		ft_swap_sa_sb(data->stack_a, data->len_a, _STACK_A, TRUE);
		ft_reverse_rra_rrb(data->stack_a, data->len_a, _STACK_A, TRUE);
	}
	else if ((data->stack_a[0] > data->stack_a[2])
		&& (data->stack_a[2] > data->stack_a[1]))
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
	else if ((data->stack_a[0] < data->stack_a[2])
		&& (data->stack_a[1] > data->stack_a[2]))
	{
		ft_swap_sa_sb(data->stack_a, data->len_a, _STACK_A, TRUE);
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
	}
	else if ((data->stack_a[0] > data->stack_a[2])
		&& (data->stack_a[1] > data->stack_a[0]))
		ft_reverse_rra_rrb(data->stack_a, data->len_a, _STACK_A, TRUE);
}

int	ft_sort_4_second(t_data *data)
{
	if (data->stack_b[0] == 2)
	{
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
		if (!ft_push_pa(data))
			return (0);
		ft_reverse_rra_rrb(data->stack_a, data->len_a, _STACK_A, TRUE);
		ft_reverse_rra_rrb(data->stack_a, data->len_a, _STACK_A, TRUE);
	}
	else if (data->stack_b[0] == 3)
	{
		if (!ft_push_pa(data))
			return (0);
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
	}
	return (1);
}

int	ft_sort_4(t_data *data)
{
	if (!ft_push_pb(data))
		return (0);
	ft_sort_3(data);
	if (data->stack_b[0] == 0)
	{
		if (!ft_push_pa(data))
			return (0);
	}
	else if (data->stack_b[0] == 1)
	{
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
		if (!ft_push_pa(data))
			return (0);
		ft_reverse_rra_rrb(data->stack_a, data->len_a, _STACK_A, TRUE);
	}
	else if (!ft_sort_4_second(data))
		return (0);
	return (1);
}

int	ft_sort_small_stack(t_data *data)
{
	if (data->len_a <= 2)
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
	else if (data->len_a == 3)
		ft_sort_3(data);
	else if (data->len_a == 4)
		if (!ft_sort_4(data))
			return (0);
	return (1);
}

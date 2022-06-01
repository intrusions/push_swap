/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:27:56 by jucheval          #+#    #+#             */
/*   Updated: 2022/06/01 17:06:07 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_5_fourth(t_data *data)
{
	if (data->stack_a[3] == 1)
	{
		ft_reverse_rra_rrb(data->stack_a, data->len_a, _STACK_A, TRUE);
		if (!ft_push_pb(data))
			return (0);
	}
	return (1);
}

int	ft_sort_5_third(t_data *data)
{
	if (data->stack_a[0] == 1)
	{
		if (!ft_push_pb(data))
			return (0);
	}
	else if (data->stack_a[1] == 1)
	{
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
		if (!ft_push_pb(data))
			return (0);
	}
	else if (data->stack_a[2] == 1)
	{
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
		if (!ft_push_pb(data))
			return (0);
	}
	else if (!ft_sort_5_fourth(data))
		return (0);
	return (1);
}

int	ft_sort_5_second(t_data *data)
{
	if (data->stack_a[3] == 0)
	{
		ft_reverse_rra_rrb(data->stack_a, data->len_a, _STACK_A, TRUE);
		ft_reverse_rra_rrb(data->stack_a, data->len_a, _STACK_A, TRUE);
		if (!ft_push_pb(data))
			return (0);
	}
	else if (data->stack_a[4] == 0)
	{
		ft_reverse_rra_rrb(data->stack_a, data->len_a, _STACK_A, TRUE);
		if (!ft_push_pb(data))
			return (0);
	}	
	return (1);
}

int	ft_sort_5_first(t_data *data)
{
	if (data->stack_a[0] == 0)
	{
		if (!ft_push_pb(data))
			return (0);
	}
	else if (data->stack_a[1] == 0)
	{
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
		if (!ft_push_pb(data))
			return (0);
	}
	else if (data->stack_a[2] == 0)
	{
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
		ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A, TRUE);
		if (!ft_push_pb(data))
			return (0);
	}
	else if (!ft_sort_5_second(data))
		return (0);
	return (1);
}

int	ft_sort_5(t_data *data)
{
	if (!ft_sort_5_first(data))
		return (0);
	if (!ft_sort_5_third(data))
		return (0);
	ft_sort_3(data);
	if (!ft_push_pa(data))
		return (0);
	if (!ft_push_pa(data))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 01:13:00 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/30 05:38:53 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_add_top_pb(t_data *data)
{
	int		*new_stack;
	int		i;
	
	i = 0;
	new_stack = malloc(sizeof(int) * (data->len_b + 1));
	if (!new_stack)
		return (0);
	new_stack[0] = data->stack_a[0];
	while (i < data->len_b)
	{
		new_stack[i + 1] = data->stack_b[i];
		i++;
	}
	free(data->stack_b);
	data->stack_b = new_stack;
	data->len_b++;
	return (1);	
}

int	ft_delete_top_pb(t_data *data)
{
	int		*new_stack;
	int		i;

	i = 0;
	new_stack = malloc(sizeof(int) * (data->len_a - 1));
	if (!new_stack)
		return (0);
	while (i < (data->len_a - 1))
	{
		new_stack[i] = data->stack_a[i + 1];
		i++;
	}
	free(data->stack_a);
	data->stack_a = new_stack;
	data->len_a--;
	return (1);
}

int    ft_push_pb(t_data *data)
{
	if (!data->len_a)
		return (1);
	if (!ft_add_top_pb(data))
		return (0);
	if (!ft_delete_top_pb(data))
		return (0);
	ft_putstr("pb\n");
	return (1);
}
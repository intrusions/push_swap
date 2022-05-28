/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 01:12:29 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/28 01:15:19 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_add_top_pa(t_data *data)
{
	int		*new_stack;
	int		i;
	
	i = 0;
	new_stack = malloc(sizeof(int) * (data->len_a + 1));
	if (!new_stack)
		return (0);
	new_stack[0] = data->stack_b[0];
	while (i <= data->len_a)
	{
		new_stack[i + 1] = data->stack_a[i];
		i++;
	}
	free(data->stack_a);
	data->stack_a = new_stack;
	data->len_a++;
	return (1);	
}

int	ft_delete_top_pa(t_data *data)
{
	int		*new_stack;
	int		i;

	i = 0;
	new_stack = malloc(sizeof(int) * (data->len_b - 1));
	if (!new_stack)
		return (0);
	while (i < (data->len_b - 1))
	{
		new_stack[i] = data->stack_b[i + 1];
		i++;
	}
	free(data->stack_b);
	data->stack_b = new_stack;
	data->len_b--;
	return (1);
}

void    ft_push_pa(t_data *data)
{
	if (!data->len_b)
		return ;
	ft_add_top_pa(data);
	ft_delete_top_pa(data);
	ft_putstr("pa\n");
}
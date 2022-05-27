/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:09:59 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/28 01:06:48 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SA | SB
void    ft_swap_sa_sb(int *stack, int len, int what_stack)
{
	int tmp;
	
	if (len <= 1)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (what_stack == _STACK_A)
		ft_putstr("sa\n");
	else if (what_stack == _STACK_B)
		ft_putstr("sb\n");
}

// SS
void    ft_swap_ss(int *stack_a, int *stack_b, int len_a, int len_b)
{
	int tmp;

	if (len_a <= 1 || len_b <= 1)
		return ;
	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
	ft_putstr("ss\n");
}

// UTILS PA
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

// UTILS PA
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

// PA
void    ft_push_pa(t_data *data)
{
	if (!data->len_b)
		return ;
	ft_add_top_pa(data);
	ft_delete_top_pa(data);
	ft_putstr("pa\n");
}

// UTILS PB
int	ft_add_top_pb(t_data *data)
{
	int		*new_stack;
	int		i;
	
	i = 0;
	new_stack = malloc(sizeof(int) * (data->len_b + 1));
	if (!new_stack)
		return (0);
	new_stack[0] = data->stack_a[0];
	while (i <= data->len_b)
	{
		new_stack[i + 1] = data->stack_b[i];
		i++;
	}
	free(data->stack_b);
	data->stack_b = new_stack;
	data->len_b++;
	return (1);	
}

// UTILS PB
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

// PB
void    ft_push_pb(t_data *data)
{
	if (!data->len_a)
		return ;
	ft_add_top_pb(data);
	ft_delete_top_pb(data);
	ft_putstr("pb\n");
}
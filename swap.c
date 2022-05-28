/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 01:10:42 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/28 02:26:40 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    ft_swap_sa_sb(int *stack, int len, int what_stack)
{
	if (len <= 1)
		return ;
    ft_swap(&stack[0], &stack[1]);
	if (what_stack == _STACK_A)
		ft_putstr("sa\n");
	else if (what_stack == _STACK_B)
		ft_putstr("sb\n");
}

void    ft_swap_ss(t_data *data)
{
	if (data->len_a <= 1 || data->len_b <= 1)
		return ;
    ft_swap(&data->stack_a[0], &data->stack_a[1]);
    ft_swap(&data->stack_b[0], &data->stack_b[1]);
	ft_putstr("ss\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 01:10:42 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/28 01:15:08 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

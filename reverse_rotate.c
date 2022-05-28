/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 02:43:05 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/28 03:12:52 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_reverse_rotate_rra_rrb(int *stack, int len, int what_stack, int print)
{
    int tmp;
    int i;

    i = len - 1;
    tmp = stack[len - 1];
    while (i >= 0)
    {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[0] = tmp;
    if (print == TRUE)
    {
        if (what_stack == _STACK_A)
            ft_putstr("rra\n");
        else if (what_stack == _STACK_B)
            ft_putstr("rrb\n");
    }
}

void    ft_reverse_rotate_rrr(t_data *data)
{
    ft_reverse_rotate_rra_rrb(data->stack_a, data->len_a, _STACK_A, FALSE);
    ft_reverse_rotate_rra_rrb(data->stack_b, data->len_b, _STACK_B, FALSE);
    ft_putstr("rrr\n");
}
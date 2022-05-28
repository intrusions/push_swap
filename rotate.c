/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 02:01:14 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/28 02:21:33 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate_ra_rb(int *stack, int len, int what_stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack[0];
	while (i < (len - 1))
	{
			stack[i] = stack[i + 1];
			i++;
	}
	stack[i] = tmp;
	if (what_stack == _STACK_A)
		ft_putstr("ra\n");
	else if (what_stack == _STACK_B)
		ft_putstr("rb\n");
}

void	ft_rotate_rr(t_data *data)
{
	ft_rotate_ra_rb(data->stack_a, data->len_a, _STACK_A);
	ft_rotate_ra_rb(data->stack_b, data->len_b, _STACK_B);
	ft_putstr("rr\n");
}
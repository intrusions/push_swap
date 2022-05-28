/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:04:11 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/28 02:29:08 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	
	data.len_a = argc - 1;
	if (argc == 1)
		return (0);
	data.stack_a = malloc(sizeof(int) * (data.len_a));					// malloc stack A with the lenght of argc - 1
	if (!data.stack_a)
		return (0);
	data.stack_b = malloc(sizeof(int) * (data.len_a));					// malloc stack B with the same lenght of A
	if (!data.stack_b)
		return (0);

	for (int i = 10, j = 0; i < 16; i++, j++)							// creat a factice B stack for making my own test
		data.stack_b[j] = i;
	data.len_b = 6;

	
	ft_fill_stack(data.stack_a, data.len_a, argv);						// fill A stack with argv input
	ft_print_stack(data.stack_a, data.len_a);							// check A stack
	ft_print_stack(data.stack_b, data.len_b);							// check B stack
	
	ft_swap_sa_sb(data.stack_a, data.len_a, _STACK_A);					// swap the 2 first int in A stack
	ft_print_stack(data.stack_a, data.len_a);							// check the result
	ft_swap_sa_sb(data.stack_b, data.len_b, _STACK_B);					// swap the 2 first int in B stack 
	ft_print_stack(data.stack_b, data.len_b);							// check the result

	ft_swap_ss(&data);		// make a SA and SB at the same time
	ft_print_stack(data.stack_a, data.len_a);							// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);							// check the result with the B stack
	
	ft_push_pa(&data); 													// swap the first int in B stack to the first in A stack
	ft_print_stack(data.stack_a, data.len_a);							// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);							// check the result with the B stack

	ft_push_pb(&data); 													// swap the first int in B stack to the first in A stack
	ft_print_stack(data.stack_a, data.len_a);							// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);							// check the result with the B stack

	ft_rotate_ra_rb(data.stack_a, data.len_a, _STACK_A);					// the first int become the last one in A STACK
	ft_rotate_ra_rb(data.stack_b, data.len_b, _STACK_B);					// the first int become the last one in B STACK
	ft_print_stack(data.stack_a, data.len_a);							// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);							// check the result with the B stack
}
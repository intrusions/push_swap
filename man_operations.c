/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:54:05 by xel               #+#    #+#             */
/*   Updated: 2022/05/28 16:54:05 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	ft_swap_sa_sb(data.stack_a, data.len_a, _STACK_A, TRUE);					// swap the 2 first int in A stack
	ft_swap_sa_sb(data.stack_b, data.len_b, _STACK_B, TRUE);					// swap the 2 first int in B stack
	ft_print_stack(data.stack_a, data.len_a);									// check the result
	ft_print_stack(data.stack_b, data.len_b);									// check the result

	ft_swap_ss(&data);															// make a SA and SB at the same time
	ft_print_stack(data.stack_a, data.len_a);									// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);									// check the result with the B stack
	
	ft_push_pa(&data); 															// swap the first int in B stack to the first in A stack
	ft_print_stack(data.stack_a, data.len_a);									// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);									// check the result with the B stack

	ft_push_pb(&data); 															// swap the first int in A stack to the first in B stack
	ft_print_stack(data.stack_a, data.len_a);									// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);									// check the result with the B stack

	ft_rotate_ra_rb(data.stack_a, data.len_a, _STACK_A, TRUE);					// shift up all elements of A stack. the first element becomes the last one
	ft_rotate_ra_rb(data.stack_b, data.len_b, _STACK_B, TRUE);					// shift up all elements of B stack. the first element becomes the last one
	ft_print_stack(data.stack_a, data.len_a);									// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);									// check the result with the B stack

	ft_rotate_rr(&data);														// the first int become the last one, for A and B stack
	ft_print_stack(data.stack_a, data.len_a);									// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);									// check the result with the B stack

	ft_reverse_rotate_rra_rrb(data.stack_a, data.len_a, _STACK_A, TRUE);		// shift down all elements of A stack. the last element becomes the first
	ft_reverse_rotate_rra_rrb(data.stack_b, data.len_b, _STACK_B, TRUE);		// shift down all elements of A stack. the last element becomes the first
	ft_print_stack(data.stack_a, data.len_a);									// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);									// check the result with the B stack

	ft_reverse_rotate_rrr(&data);												// shift down all elements of A and B stack
	ft_print_stack(data.stack_a, data.len_a);									// check the result with the A stack
	ft_print_stack(data.stack_b, data.len_b);									// check the result with the B stack

	for (int i = 10, j = 0; i < 16; i++, j++) 									// fill a factice B stack for making my own test
		data->stack_b[j] = i;
	data->len_b = 6;
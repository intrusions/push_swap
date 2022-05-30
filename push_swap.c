/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:04:11 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/30 06:19:56 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_prepare_stack(t_data *data, int argc, char **argv)
{
	if (argc == 1)
		return (0);
	data->len_a = argc - 1;
	if (!ft_parsing(argv, data->len_a))
		return (0);
	data->stack_a = malloc(sizeof(int) * (data->len_a));
	if (!data->stack_a)
		return (0);
	data->stack_b = malloc(sizeof(int) * (data->len_a));
	if (!data->stack_b)
		return (free(data->stack_a), 0);
	ft_fill_stack(data->stack_a, data->len_a, argv);
	if (!ft_check_duplicate_and_max(data->stack_a, data->len_a))
		return (free(data->stack_a), free(data->stack_b), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init_struct(&data);
	if (!ft_prepare_stack(&data, argc, argv))
		return (ft_error());
	ft_sort(&data);
	ft_print_stack(data.stack_a, data.len_a);
	return (free(data.stack_a), free(data.stack_b), 0);
}
